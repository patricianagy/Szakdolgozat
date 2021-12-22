#include "regionbasedsegmentation.h"
#include<time.h>

RegionBasedSegmentation::RegionBasedSegmentation()
{
    srand(time(NULL));
}

void RegionBasedSegmentation::chooseSeedPoints(cv::Mat img)
{
  int rows = img.rows/5;
  int cols = img.cols/4;
  int k=0;

     for(int i=0; i<5; i++){
         for(int j=0; j<4; j++){
             seedPoints[k].first = rand() % rows*(i+1) + rows*i ;
             seedPoints[k].second = rand() % cols*(j+1) + cols*j ;
             k++;
         }
     }

}

void RegionBasedSegmentation::initRegions()
{
    for(int i=0; i<20; i++){
        regionsR[i].clear();
        regionsG[i].clear();
        regionsB[i].clear();
        regionsR[i].push_back(seedPoints[i]);
        regionsG[i].push_back(seedPoints[i]);
        regionsB[i].push_back(seedPoints[i]);
    }
}

int RegionBasedSegmentation::mean(QVector<QPair<int, int> > region, cv::Mat img, int channel)
{
    int sum = 0;

    for(int i=0; i<region.size(); i++){
        sum += img.at<cv::Vec3b>(region[i].first, region[i].second)[channel];
    }

    return sum/region.size();
}

bool RegionBasedSegmentation::isInside(QVector<QPair<int, int> > region, int i, int j, QVector<QPair<int, int> > regions[])
{
    for(int l=0; l<20; l++){
        for(int k=0; k<regions[l].size(); k++){
            if(regions[l][k].first==i && regions[l][k].second==j){
                return true;
            }
        }
    }
    return false;
}



void RegionBasedSegmentation::pixelAggregation(cv::Mat img, int channel, int threshold, QVector<QPair<int, int> > regions[])
{
    bool notFinished;
    int pixel;
    for(int i=0; i<20; i++){
        notFinished=true;
        pixel = 0;
        while (notFinished) {
            for (int j=-1; j<2; j++){
                for (int k=-1; k<2; k++){
                    if( regions[i][pixel].first+j>=0 && regions[i][pixel].first+j<img.rows &&
                            regions[i][pixel].second+k>=0 && regions[i][pixel].second+k<img.cols &&
                            !isInside(regions[i], regions[i][pixel].first+j,regions[i][pixel].second+k, regions)  ){
                        int sum = std::abs(img.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[channel]-mean(regions[i], img, channel));
                        if(sum<=threshold){
                            QPair<int,int> coordinates;
                            coordinates.first=regions[i][pixel].first+j;
                            coordinates.second= regions[i][pixel].second+k;
                            regions[i].push_back(coordinates);
                        }
                    }
                }
            }
            pixel++;
            if(pixel == regions[i].size()){
                notFinished=false;
            }

        }
    }

}

void RegionBasedSegmentation::segmentation(cv::Mat img, int threshold)
{
    chooseSeedPoints(img);
    initRegions();
    pixelAggregation(img,0,threshold,regionsR);
    pixelAggregation(img,0,threshold,regionsG);
    pixelAggregation(img,0,threshold,regionsB);
}

int RegionBasedSegmentation::findPixel(int i, int j, QVector<QPair<int, int> > region[], cv::Mat img, int channel)
{
    for(int k=0; k<20; k++){
        for(int l=0; l<region[k].size(); l++){
            if(region[k][l].first==i && region[k][l].second==j){
                return img.at<cv::Vec3b>(seedPoints[k].first, seedPoints[k].second)[channel];
            }
        }
    }
    return 0;
}

void RegionBasedSegmentation::setValue(cv::Mat helper,cv::Mat img, int i, int j)
{
    helper.at<cv::Vec3b>(i, j)[0] = findPixel(i,j,regionsR,img,0);
    helper.at<cv::Vec3b>(i, j)[1] = findPixel(i,j,regionsG,img,1);
    helper.at<cv::Vec3b>(i, j)[2] = findPixel(i,j,regionsB,img,2);
}

