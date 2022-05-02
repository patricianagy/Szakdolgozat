#include "dataaccess.h"
#include <QFile>
#include <iostream>

DataAccess::DataAccess()
{

}

cv::Mat DataAccess::loadPicture(QString fileName)
{
    QFile file(fileName);
    std::vector<char> buffer;
    buffer.resize(file.size());
    if (!file.open(QIODevice::ReadOnly)) {
        return cv::Mat();
    }
    file.read(buffer.data(), file.size());
    file.close();
    cv::Mat img = cv::imdecode(buffer, cv::COLOR_BGR2RGB);
    //cv:: Mat img = cv::imread(fileName.toStdString());
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    return img;
}

void DataAccess::savePicture(QString fileName, cv::Mat img)
{
    std::vector<uchar> buffer;
    QStringList name = fileName.split(QLatin1Char('.'));
    QString extention = ".";
    extention.append(name[1]);
    cv::cvtColor(img,img,cv::COLOR_RGB2BGR);
    cv::imencode(extention.toStdString(),img,buffer);


    std::ofstream imgOut(std::wstring(reinterpret_cast<const wchar_t*>(fileName.utf16())), std::ios::out | std::ios::binary);
    imgOut.write((const char*)&buffer[0], buffer.size());

    imgOut.close();





}
