#include "histogramsmoothing.h"

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"



HistogramSmoothing::HistogramSmoothing()
{
    pixelCount = 0;

    histB->clear();
    histG->clear();
    histR->clear();

    for(int i=0; i<256; i++){
        nHistB[i] = 0;
        nHistG[i] = 0;
        nHistR[i] = 0;
    }


}

void HistogramSmoothing::calcHistogram(cv::Mat img)
{




    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){


            int r= img.at<cv::Vec3b>(i, j)[0]*1;
            int g= img.at<cv::Vec3b>(i, j)[1]*1;
            int b= img.at<cv::Vec3b>(i, j)[2]*1;

            unsigned char* rPixel = &img.at<cv::Vec3b>(i, j)[0];
            unsigned char* gPixel = &img.at<cv::Vec3b>(i, j)[1];
            unsigned char* bPixel = &img.at<cv::Vec3b>(i, j)[2];

            histR[r].push_back(rPixel);
            histG[g].push_back(gPixel);
            histB[b].push_back(bPixel);
            pixelCount++;
        }
    }




  normalizeHist(histR,nHistR);
  normalizeHist(histG,nHistG);
  normalizeHist(histB,nHistB);

  equalization(nHistR,histR);
  equalization(nHistG,histG);
  equalization(nHistB,histB);



  for(int i=0 ; i<256; i++){

      for(int j=0; j<histR[i].size(); j++){
          *histR[i][j]=(unsigned char)i;
      }
      for(int j=0; j<histG[i].size(); j++){
          *histG[i][j]=(unsigned char)i;
      }
      for(int j=0; j<histB[i].size(); j++){
          *histB[i][j]=(unsigned char)i;
      }
  }

}



int HistogramSmoothing::findMin(int hist[])
{
    for(int i=0; i<256; i++){
        if(hist[i]!=0){
            return hist[i];
        }
    }

    return 0;
}




void HistogramSmoothing::normalizeHist( QVector<unsigned char*>hist[],  int nHist[])
{

    for(int i=0; i<256; i++){
        for(int j=0; j<=i; j++){
            nHist[i] = nHist[i] + hist[j].size();

        }

    }

}

void HistogramSmoothing::equalization(int nHist[] ,QVector<unsigned char*>hist[])
{
    int equalizedHist[256];
    for(int i=0; i<256; i++){
        equalizedHist[i]=0;
    }
    int min = findMin(nHist);
    int result=0;
    double d = pixelCount-min;


    for(int i=0; i<256; i++) {

        result = std::round((nHist[i]-min)*255/d);
        equalizedHist[i]= result<0 ? 0 : result;

    }

    for(int i=0; i<256; i++){
        if(i!=equalizedHist[i]){
            while(hist[i].size()>0){
                hist[equalizedHist[i]].append(hist[i].last());
                hist[i].pop_back();
            }
        }

    }



}





void HistogramSmoothing::clean()
{
    pixelCount=0;



    for(int i = 0; i<256; i++){

        histR[i].clear();
        histG[i].clear();
        histB[i].clear();

    }

    for(int i=0; i<256; i++){
        nHistB[i] = 0;
        nHistG[i] = 0;
        nHistR[i] = 0;
    }

}









