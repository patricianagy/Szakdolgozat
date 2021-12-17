#ifndef HISTOGRAMSMOOTHING_H
#define HISTOGRAMSMOOTHING_H

#include <QVector>
#include <QPair>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
class HistogramSmoothing
{
public:
    HistogramSmoothing();
    void calcHistogram(cv::Mat img);
    void print();
    int findMin(int hist[]);
    int findMax(int hist[]);
    void normalizeHist( QVector<QPair<int,int>>hist[], int nHist[]);
    void equalization(int nHist[], QVector<QPair<int,int>>hist[]);
    int findPixel(int i, int j, QVector<QPair<int,int>>hist[]);
    void smoothing(cv::Mat img,int i, int j );

private:
      int pixelCount;

      QVector<QPair<int,int>>histR[256];
      QVector<QPair<int,int>>histG[256];
      QVector<QPair<int,int>>histB[256];

      int nHistR[256];
      int nHistG[256];
      int nHistB[256];
};

#endif // HISTOGRAMSMOOTHING_H
