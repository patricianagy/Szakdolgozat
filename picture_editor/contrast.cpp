#include "contrast.h"
#include <iostream>

Contrast::Contrast()
{

}

int Contrast::calculateChannel(double size, cv::Mat img, int channel, int i, int j)
{

    float pixel = img.at<cv::Vec3b>(i, j)[channel];

    if(pixel*size>=255) return 255;
    if(pixel*size==0) return 0;

    return pixel*size;
}

void Contrast::calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int size)
{

    size2=size/10.0;



    img.at<cv::Vec3b>(i, j)[0] = calculateChannel(size2,helper, 0, i, j );
    img.at<cv::Vec3b>(i, j)[1] = calculateChannel(size2, helper, 1, i, j );
    img.at<cv::Vec3b>(i, j)[2] = calculateChannel(size2, helper, 2, i, j );


}
