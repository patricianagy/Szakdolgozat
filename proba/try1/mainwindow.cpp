#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTimer>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

        Timer = new QTimer(this);
        Timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_image(QString image_path){
    cv::Mat img;
    img = cv::imread(image_path.toStdString());
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "C:/",
                                                        tr("Images (*.png *.jpg)"));
    display_image(fileName);
}

