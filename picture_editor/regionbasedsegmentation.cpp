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


  std::random_device rd;
  std::mt19937 gen(rd());

     for(int i=0; i<5; i++){
         for(int j=0; j<4; j++){


             std::uniform_int_distribution<int> distr(i*rows, ((i+1)*rows)-1);
             int r = distr(gen) ;

             std::uniform_int_distribution<int> dist(j*cols, ((j+1)*cols)-1);
             int c = dist(gen) ;

             seedPoints[k].first = r ;
             seedPoints[k].second = c ;

             k++;


         }
     }


}

void RegionBasedSegmentation::initRegions()
{
    for(int i=0; i<20; i++){
        regions[i].clear();

        regions[i].push_back(seedPoints[i]);

    }
}

int RegionBasedSegmentation::mean(QVector<QPair<int, int> > region, cv::Mat img, int channel)
{
    int sum = 0;

    for(int i=0; i<region.size(); i++){
        sum = sum + img.at<cv::Vec3b>(region[i].first, region[i].second)[channel];
    }

    return sum/region.size();
}

bool RegionBasedSegmentation::isNotInside( int i, int j)
{
    for(int l=0; l<20; l++){
        for(int k=0; k<regions[l].size(); k++){
            if(regions[l][k].first==i && regions[l][k].second==j){
                return false;
            }
        }
    }
    return true;
}



void RegionBasedSegmentation::pixelAggregation(cv::Mat helper,cv::Mat img, int channel, int threshold)
{
    bool notFinished;
    int pixel;
    for(int i=0; i<20; i++){
        notFinished=true;
        pixel = 0;
        while (notFinished) {
            for (int j=-1; j<=1; j++){
                for (int k=-1; k<=1; k++){
                    if( regions[i][pixel].first+j>=0 && regions[i][pixel].first+j<img.rows &&
                            regions[i][pixel].second+k>=0 && regions[i][pixel].second+k<img.cols &&
                            isNotInside(regions[i][pixel].first+j,regions[i][pixel].second+k) ){
                        int sum = std::abs(img.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[channel]-mean(regions[i], img, channel));
                        if(sum<=threshold){
                            QPair<int,int> coordinates;
                            coordinates.first=regions[i][pixel].first+j;
                            coordinates.second= regions[i][pixel].second+k;
                            regions[i].push_back(coordinates);
                            helper.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[0]=img.at<cv::Vec3b>(seedPoints[i].first, seedPoints[i].second)[0];
                            helper.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[1]=img.at<cv::Vec3b>(seedPoints[i].first, seedPoints[i].second)[1];
                            helper.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[2]=img.at<cv::Vec3b>(seedPoints[i].first, seedPoints[i].second)[2];
                        }
                    }
                }
            }
            pixel++;
            if(pixel >= regions[i].size()){
                notFinished=false;
            }

        }
    }

}

void RegionBasedSegmentation::segmentation(cv::Mat helper,cv::Mat img, int threshold)
{
    chooseSeedPoints(img);
    initRegions();
    pixelAggregation(helper,img,0,threshold);


}


