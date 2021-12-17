#include "regionbasedsegmentation.h"
#include<time.h>

RegionBasedSegmentation::RegionBasedSegmentation()
{
    srand(time(NULL));
}

/*void RegionBasedSegmentation::chooseSeedPoints(cv::Mat img)
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
        regions[i].push_back(seedPoints[i]);
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

void RegionBasedSegmentation::pixelAggregation(cv::Mat img, int channel)
{
    bool notFinished;
    int pixel;
    for(int i=0; i<20; i++){
        notFinished=true;
        pixel = 0;
        while (notFinished) {
            for (int j=-1; j<2; j++){
                for (int k=-1; k<2; k++){
                    int sum = std::abs(img.at<cv::Vec3b>(regions[i][pixel].first+j, regions[i][pixel].second+k)[channel]-mean(regions[i], img, channel));
                    if(sum<=threshold){
                        QPair<int,int> coordinates;
                        coordinates.first=regions[i][pixel].first+j;
                        coordinates.second= regions[i][pixel].second+k;
                        regions[i].push_back(coordinates);
                    }
                }
            }
            if(pixel == regions[i].size()){
                notFinished=false;
            }else{
                pixel++;
            }
        }
    }
}*/


