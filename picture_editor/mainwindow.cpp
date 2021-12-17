#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QSlider>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sliderPlace = ui->sliderLayout;

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(openPicture()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(savePicture()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    connect(ui->blurButton, SIGNAL(clicked()), this, SLOT(gaussBlur()));
    connect(ui->brightButton, SIGNAL(clicked()), this, SLOT(setBrightness()));
    connect(ui->contrastButton, SIGNAL(clicked()), this, SLOT(setContrast()));
    connect(ui->histogramButton, SIGNAL(clicked()), this, SLOT(histogramSmoothing()));
    connect(ui->rgsButton, SIGNAL(clicked()), this, SLOT(rgs()));

    model = new Model();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayImage(cv::Mat img)
{

    int w = ui->displayImage->width();
    int h = ui->displayImage->height();
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->displayImage->setPixmap(QPixmap::fromImage(imdisplay).scaled(w,h,Qt::KeepAspectRatio));
    ui->displayImage->setAlignment(Qt::AlignCenter);


}

void MainWindow::openPicture()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "",
                                                        tr("Images (*.png *.jpg)"));
    if(!fileName.isEmpty()){
        model ->setFileName(fileName);
        model->load();
        displayImage(model->getImage());

    }

}

void MainWindow::savePicture()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "",
                                                        tr("Images (*.png *.jpg)"));

    model->save(fileName);
}

void MainWindow::cancel()
{
    model->cancel();
    displayImage(model->getImage());
}

void MainWindow::gaussBlur()
{
    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->itemAt(0)->widget()->deleteLater();
    model->changeFunction(Model::Functions::GAUSS);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,7);
    slider->setSliderPosition(1);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(gaussChange(int)));
    displayImage(model->getImage());
}

void MainWindow::gaussChange(int kernel)
{
    if(kernel!=2 && kernel!=4 && kernel!=6){
        model->executeEdit(Model::Functions::GAUSS,kernel);
        displayImage(model->getHelper());
    }
}

void MainWindow::setBrightness()
{

    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->itemAt(0)->widget()->deleteLater();
    model->changeFunction(Model::Functions::BRIGHTNESS);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(-100,100);
    slider->setSliderPosition(0);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(brightnessChange(int)));
    displayImage(model->getImage());

}

void MainWindow::brightnessChange(int size)
{
    model->executeEdit(Model::Functions::BRIGHTNESS,size);
    displayImage(model->getHelper());
}

void MainWindow::setContrast()
{

     if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->itemAt(0)->widget()->deleteLater();
     model->changeFunction(Model::Functions::CONTRAST);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,30);
    slider->setSliderPosition(10);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(contrastChange(int)));
    displayImage(model->getImage());
}

void MainWindow::contrastChange(int size)
{
    model->executeEdit(Model::Functions::CONTRAST,size);
    displayImage(model->getHelper());
}

void MainWindow::histogramSmoothing()
{

    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->itemAt(0)->widget()->deleteLater();
    displayImage(model->getImage());
    model->changeFunction(Model::Functions::HISTOGRAM);
    model->executeEdit(Model::Functions::HISTOGRAM);
    displayImage(model->getHelper());
}

void MainWindow::rgs()
{
    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->itemAt(0)->widget()->deleteLater();
    model->changeFunction(Model::Functions::RGS);
    model->executeEdit(Model::Functions::RGS);
    displayImage(model->getHelper());
}

