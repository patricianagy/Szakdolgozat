#ifndef CONTRAST_H
#define CONTRAST_H


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Contrast
{
public:
    Contrast();
    int calculateChannel(double size, cv::Mat img, int channel, int i, int j);
    void calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int size);

private:
    double size2;

};

#endif // CONTRAST_H
