#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
    model ->setFileName(fileName);
    model->load();
    displayImage(model->getImage());

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
    model->executeEdit(Model::Functions::GAUSS);
    displayImage(model->getImage());
}

void MainWindow::setBrightness()
{
    model->executeEdit(Model::Functions::BRIGHTNESS);
    displayImage(model->getImage());
}

void MainWindow::setContrast()
{
    model->executeEdit(Model::Functions::CONTRAST);
    displayImage(model->getImage());
}

