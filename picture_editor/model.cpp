#include "model.h"
#include <iostream>


Model::Model()
{
    data = new dataAccess();
    gaussianBlur = new GaussBlur();
    brightnessSetting = new Brightness();
    contrast = new Contrast();

    function=Functions::GAUSS;

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

cv::Mat Model::getHelper()
{
    return helper;
}

void Model::load()
{
    img=data->loadPicture(fileName);

    helper=img.clone();
}

void Model::save(QString name)
{
    data->savePicture(name, img);
}

void Model::executeEdit(Functions function, int size)
{

    helper=img.clone();
    cv::cvtColor(helper,helper,cv::COLOR_BGR2RGB);
    for( int i = 0; i < helper.rows; ++i) {
      for( int j = 0; j < helper.cols; ++j) {
          switch (function) {
            case Functions::GAUSS:
                gaussianBlur->calculatePixel(helper,img,i,j,size);
                break;
            case Functions::BRIGHTNESS:
                brightnessSetting->calculatePixel(helper,img,i,j,size);
                break;
            case Functions::CONTRAST:
                contrast->calculatePixel(helper,img,i,j,size);
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


}

void Model::changeFunction(Functions func)
{

    if(function != func){
        img=helper.clone();
    }
    function = func;

}


