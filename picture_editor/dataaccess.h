#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <fstream>

class DataAccess
{
public:
    DataAccess();
    cv::Mat loadPicture(QString fileName);
    void savePicture(QString fileName, cv::Mat img);
};

#endif // DATAACCESS_H
