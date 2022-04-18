#ifndef REGIONBASEDSEGMENTATION_H
#define REGIONBASEDSEGMENTATION_H

#include <random>
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
    void pixelAggregation(cv::Mat helper,cv::Mat img, int channel, int threshold);
    bool isNotInside( int i, int j);
    void segmentation(cv::Mat helper,cv::Mat img, int threshold);


private:
    QPair<int,int> seedPoints[15];
    QVector<QPair<int,int>> regions[15];



};

#endif // REGIONBASEDSEGMENTATION_H
