#include "dataaccess.h"
#include <iostream>

DataAccess::DataAccess()
{

}

cv::Mat DataAccess::loadPicture(QString fileName)
{
    cv::Mat img = cv::imread(fileName.toStdString());
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    return img;

}

void DataAccess::savePicture(QString fileName, cv::Mat img)
{
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    cv::imwrite(fileName.toStdString(),img);
}
