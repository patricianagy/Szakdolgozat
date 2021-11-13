#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "model.h"

class dataAccess
{
public:
    dataAccess();
    void loadPicture();
    void savePicture();
};

#endif // DATAACCESS_H
