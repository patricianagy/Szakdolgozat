#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:    // A slot or function is defined which will be intiated by timer
void display_image(QString image_path);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
