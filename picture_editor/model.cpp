#include "model.h"
#include <QFileDialog>
#include <QTimer>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>


Model::Model()
{

}

void Model::setFileName(QString name)
{
    fileName=name;
}

QString Model::getFileName()
{
 return fileName;
}
