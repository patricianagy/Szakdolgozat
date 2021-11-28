#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    Model *model;

private slots:
    void open_picture();
    void save_picture();
    void gaussBlur();
    void setBrightness();
    void setContrast();
};
#endif // MAINWINDOW_H
