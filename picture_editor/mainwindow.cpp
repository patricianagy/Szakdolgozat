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
    slider = new QSlider(Qt::Horizontal);

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(open_picture()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save_picture()));

    connect(ui->blurButton, SIGNAL(clicked()), this, SLOT(gaussBlur()));
    connect(ui->brightButton, SIGNAL(clicked()), this, SLOT(setBrightness()));
    connect(ui->contrastButton, SIGNAL(clicked()), this, SLOT(setContrast()));

    model = new Model();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayImage(cv::Mat img)
{

    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->displayImage->setPixmap(QPixmap::fromImage(imdisplay));

}

void MainWindow::open_picture()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "C:",
                                                        tr("Images (*.png *.jpg)"));
    if(!fileName.isEmpty()){
        model ->setFileName(fileName);
        model->load();
        displayImage(model->getImage());

    }

}

void MainWindow::save_picture()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "C:",
                                                        tr("Images (*.png *.jpg)"));

    model->save(fileName);
}

void MainWindow::gaussBlur()
{
    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->removeWidget(slider);
    model->changeFunction(Model::Functions::GAUSS);

    slider->setRange(1,7);
    slider->setSingleStep(2);
    slider->setSliderPosition(1);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(gaussChange(int)));

}

void MainWindow::gaussChange(int kernel)
{
    model->executeEdit(Model::Functions::GAUSS,kernel);
    displayImage(model->getHelper());
}

void MainWindow::setBrightness()
{

    if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->removeWidget(slider);
    model->changeFunction(Model::Functions::BRIGHTNESS);


    slider->setRange(-100,100);
    slider->setSliderPosition(0);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(brightnessChange(int)));

}

void MainWindow::brightnessChange(int size)
{
    model->executeEdit(Model::Functions::BRIGHTNESS,size);
    displayImage(model->getHelper());
}

void MainWindow::setContrast()
{
     if(!(ui->sliderLayout->isEmpty())) ui->sliderLayout->removeWidget(slider);
     model->changeFunction(Model::Functions::CONTRAST);

    slider->setRange(0,30);
    slider->setSliderPosition(10);

    ui->sliderLayout->addWidget(slider);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(contrastChange(int)));
}

void MainWindow::contrastChange(int size)
{
    model->executeEdit(Model::Functions::CONTRAST,size);
    displayImage(model->getHelper());
}

