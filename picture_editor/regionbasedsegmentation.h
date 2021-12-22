#ifndef REGIONBASEDSEGMENTATION_H
#define REGIONBASEDSEGMENTATION_H

#include <QVector>
#include <QPair>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

class RegionBasedSegmentation
{
public:
    RegionBasedSegmentation();
    void chooseSeedPoints(cv::Mat img);
    void initRegions();
    int mean(QVector<QPair<int,int>> region, cv::Mat img, int channel);
    void pixelAggregation(cv::Mat img, int channel, int threshold, QVector<QPair<int, int> > regions[]);
    bool isInside(QVector<QPair<int, int> > region, int i, int j, QVector<QPair<int, int> > regions[]);
    int findPixel(int i, int j, QVector<QPair<int,int>> region[20], cv::Mat img, int channel);
    void segmentation(cv::Mat img, int threshold);
    void setValue(cv::Mat helper,cv::Mat img, int i, int j);

private:
    QPair<int,int> seedPoints[20];
    QVector<QPair<int,int>> regionsR[20];
    QVector<QPair<int,int>> regionsG[20];
    QVector<QPair<int,int>> regionsB[20];


};

#endif // REGIONBASEDSEGMENTATION_H
