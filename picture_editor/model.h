#ifndef MODEL_H
#define MODEL_H

#include "brightness.h"
#include "contrast.h"
#include "dataaccess.h"
#include "gaussblur.h"
#include "histogramsmoothing.h"
#include "regionbasedsegmentation.h"


#include <QString>
#include <QObject>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Model : public  QObject
{
     Q_OBJECT

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
    cv::Mat getHelper();
    void load();
    void save(QString name);
    void cancel();
    void executeEdit(Functions function, int size=0);
    void changeFunction(Functions func);
    bool notTooBigPicture();

signals:
    void tooBigPicture();

private:
    DataAccess *data;
    GaussBlur *gaussianBlur;
    Brightness *brightnessSetting;
    Contrast *contrast;
    HistogramSmoothing *histogram;
    RegionBasedSegmentation *rgs;
    QString fileName;
    cv::Mat img;
    cv::Mat helper;
    Functions function;
    QVector<cv::Mat> previousStates;
};

#endif // MODEL_H
