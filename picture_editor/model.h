#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Model
{
public:
    Model();
    void setFileName(QString name);
    QString getFileName();

private:
    QString fileName;
};

#endif // MODEL_H
