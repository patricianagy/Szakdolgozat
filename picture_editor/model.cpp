#include "model.h"
#include <iostream>


Model::Model()
{
    data = new dataAccess();
    gaussianBlur = new GaussBlur();
    brightnessSetting = new Brightness();
    contrast = new Contrast();

}

void Model::setFileName(QString name)
{
    fileName=name;
}

QString Model::getFileName()
{
    return fileName;
}

void Model::setImage(cv::Mat image)
{
    img = image;
}

cv::Mat Model::getImage()
{
    return img;
}

void Model::load()
{
    img=data->loadPicture(fileName);
}

void Model::save(QString name)
{
    data->savePicture(name, img);
}

void Model::executeEdit(Functions function)
{
    cv::Mat helper =  img;
    cv::cvtColor(helper,helper,cv::COLOR_BGR2RGB);
    for( int i = 0; i < img.rows; ++i) {
      for( int j = 0; j < img.cols; ++j) {
          switch (function) {
            case Functions::GAUSS:
                gaussianBlur->calculatePixel(img,helper,i,j,5);
                break;
            case Functions::BRIGHTNESS:
                brightnessSetting->calculatePixel(img,helper,i,j,50);
                break;
            case Functions::CONTRAST:
                contrast->calculatePixel(img,helper,i,j,0.7);
                break;
            case Functions::HISTOGRAM:
                break;
            case Functions::RGS:
                break;
            default:
                std::cout<<"Invalid function";
                break;
          }

      }
    }
    cv::cvtColor(img, img,cv::COLOR_BGR2RGB);

}


