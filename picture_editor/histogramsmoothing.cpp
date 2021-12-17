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
    histB->clear();
    histG->clear();
    histR->clear();

    for(int i=0; i<256; i++){
        nHistB[i] = 0;
        nHistG[i] = 0;
        nHistR[i] = 0;
    }

     QPair<int,int> coordinates;

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            coordinates.first = i;
            coordinates.second = j;

            int r= img.at<cv::Vec3b>(i, j)[0]*1;
            int g= img.at<cv::Vec3b>(i, j)[1]*1;
            int b= img.at<cv::Vec3b>(i, j)[2]*1;

            histR[r].push_back(coordinates);
            histG[g].append(coordinates);
            histB[b].append(coordinates);

            pixelCount++;
        }
    }

  normalizeHist(histR,nHistR);
  normalizeHist(histG,nHistG);
  normalizeHist(histB,nHistB);

  equalization(nHistR,histR);
  equalization(nHistG,histG);
  equalization(nHistB,histB);

}

void HistogramSmoothing::print()
{


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




void HistogramSmoothing::normalizeHist( QVector<QPair<int,int>>hist[],  int nHist[])
{

    for(int i=0; i<256; i++){
        for(int j=0; j<=i; j++){
            nHist[i] = nHist[i] + hist[j].size();

        }

    }

}

void HistogramSmoothing::equalization(int nHist[] ,QVector<QPair<int,int>>hist[])
{
    int equalizedHist[256];
    for(int i=0; i<256; i++){
        equalizedHist[i]=0;
    }
    int min = findMin(nHist);
    int result;


    for(int i=0; i<256; i++) {
        result = std::round((nHist[i]-min)/(double)(pixelCount-min)*255);
        equalizedHist[i]= result<0 ? 0 : result;
    }

    for(int i=0; i<256; i++){
        if(i!=equalizedHist[i]){
            while(!hist[i].empty()){
                hist[equalizedHist[i]].append(hist[i].last());
                hist[i].removeLast();
            }
        }
    }

}

int HistogramSmoothing::findPixel(int i, int j,QVector<QPair<int,int>>hist[])
{

    for(int k=0; k<256; k++){
        if(hist[k].size()!=0){
            for(int l=0; l<hist[k].size(); l++){
                if(i==hist[k][l].first && j==hist[k][l].second){
                    hist[k].remove(l);
                    return k;
                }
            }
        }
    }
    return 0;
}

void HistogramSmoothing::smoothing(cv::Mat img, int i, int j)
{
    img.at<cv::Vec3b>(i, j)[0] = findPixel(i,j,histR);
    img.at<cv::Vec3b>(i, j)[1] = findPixel(i,j,histG);
    img.at<cv::Vec3b>(i, j)[2] = findPixel(i,j,histB);
}









