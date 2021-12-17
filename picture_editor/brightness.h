#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Brightness
{
public:
    Brightness();
    int calculateChannel(int size, cv::Mat img, int channel, int i, int j);
    void calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int size);

};

#endif // BRIGHTNESS_H
