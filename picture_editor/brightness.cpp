#include "brightness.h"
#include <iostream>

Brightness::Brightness()
{

}

int Brightness::calculateChannel(int size, cv::Mat img, int channel, int i, int j)
{
    float pixel = img.at<cv::Vec3b>(i, j)[channel];

    if(pixel+size>=255) return 255;
    if(pixel+size<=0) return 0;

    return pixel+size;
}

void Brightness::calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int size)
{
    img.at<cv::Vec3b>(i, j)[0] = calculateChannel(size,helper, 0, i, j );
    img.at<cv::Vec3b>(i, j)[1] = calculateChannel(size, helper, 1, i, j );
    img.at<cv::Vec3b>(i, j)[2] = calculateChannel(size, helper, 2, i, j );
}
