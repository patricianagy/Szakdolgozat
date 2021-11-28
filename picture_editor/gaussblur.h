#ifndef GAUSSBLUR_H
#define GAUSSBLUR_H

#include <QVector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class GaussBlur
{
public:
    GaussBlur();
    float calculateKernel(int kernel, cv::Mat img, int channel, int i, int j);
    void calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int kernel);

private:
   QVector<QVector<int>> low;
   QVector<QVector<int>> medium;
   QVector<QVector<int>> high;
};

#endif // GAUSSBLUR_H
