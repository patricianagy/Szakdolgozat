#ifndef MODEL_H
#define MODEL_H

#include "brightness.h"
#include "contrast.h"
#include "dataaccess.h"
#include "gaussblur.h"


#include <QString>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Model
{
public:
    Model();

   enum class Functions
    {
        GAUSS,
        BRIGHTNESS,
        CONTRAST,
        HISTOGRAM,
        RGS,
    };

    void setFileName(QString name);
    QString getFileName();
    void setImage(cv::Mat image);
    cv::Mat getImage();
    void load();
    void save(QString name);
    void executeEdit(Functions function);


private:
    dataAccess *data;
    GaussBlur *gaussianBlur;
    Brightness *brightnessSetting;
    Contrast *contrast;
    QString fileName;
    cv::Mat img;

};

#endif // MODEL_H
