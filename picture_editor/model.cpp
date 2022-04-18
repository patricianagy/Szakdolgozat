#include "model.h"
#include <iostream>


Model::Model()
{
    data = new DataAccess();
    gaussianBlur = new GaussBlur();
    brightnessSetting = new Brightness();
    contrast = new Contrast();
    histogram = new HistogramSmoothing();
    rgs = new RegionBasedSegmentation();

    function=Functions::GAUSS;
    previousStates.clear();


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
    img = image.clone();
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
    img=data->loadPicture(fileName).clone();

    helper=img.clone();
    previousStates.clear();
    cv::Mat first = img.clone();
    previousStates.push_back(first);

}

void Model::save(QString name)
{
    img=helper.clone();
    if(name!="") data->savePicture(name, img);

}

void Model::cancel()
{

  img=previousStates.last().clone();
  if(previousStates.size() != 1){
      previousStates.removeLast();
  }

}

void Model::executeEdit(Functions function, int size)
{
    if(!img.empty()){

        helper=img.clone();
        if(function==Functions::HISTOGRAM){
            histogram->calcHistogram(helper);
            histogram->clean();
            return;
        }

        if(function==Functions::RGS){
            rgs->segmentation(helper,img,2);
            return;
        }

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
                default:
                    std::cout<<"Invalid function ";
                    break;
              }


          }
        }




    }

}

void Model::changeFunction(Functions func)
{

    if(function != func){
        img=helper.clone();
        cv::Mat currentImg= img.clone();
        previousStates.push_back(currentImg);
    }
    function = func;


}


