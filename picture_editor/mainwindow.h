#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qboxlayout.h>
#include <qslider.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayImage(cv::Mat img);

private:
    Ui::MainWindow *ui;
    QHBoxLayout *sliderPlace;
    QSlider *slider;
    Model *model;

private slots:
    void openPicture();
    void savePicture();
    void cancel();
    void gaussBlur();
    void gaussChange(int kernel);
    void setBrightness();
    void brightnessChange(int size);
    void setContrast();
    void contrastChange(int size);
    void histogramSmoothing();
    void rgs();

};
#endif // MAINWINDOW_H
