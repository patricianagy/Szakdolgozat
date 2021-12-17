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
    void pixelAggregation(cv::Mat img, int channel);

private:
    QPair<int,int> seedPoints[20];
    int threshold;
    QVector<QPair<int,int>> regions[20];

};

#endif // REGIONBASEDSEGMENTATION_H
