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
    void normalizeHist( QVector<unsigned char*>hist[], int nHist[]);
    void equalization(int nHist[], QVector<unsigned char*>hist[]);
    void clean();

private:
      int pixelCount;

      QVector<unsigned char*>histR[256];
      QVector<unsigned char*>histG[256];
      QVector<unsigned char*>histB[256];

      int nHistR[256];
      int nHistG[256];
      int nHistB[256];
};

#endif // HISTOGRAMSMOOTHING_H
