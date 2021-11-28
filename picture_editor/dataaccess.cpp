#include "dataaccess.h"
#include <iostream>

dataAccess::dataAccess()
{

}

cv::Mat dataAccess::loadPicture(QString fileName)
{
    cv::Mat img = cv::imread(fileName.toStdString());
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    return img;

}

void dataAccess::savePicture(QString fileName, cv::Mat img)
{
    cv::imwrite(fileName.toStdString(),img);
}
