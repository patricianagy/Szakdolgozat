QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

LIBS += -LC:\opencv_build\install\x86\vc15\lib -lopencv_core453d -lopencv_imgproc453d -lopencv_highgui453d -lopencv_imgcodecs453d -lopencv_videoio453d -lopencv_video453d -lopencv_calib3d453d -lopencv_photo453d -lopencv_features2d453d

INCLUDEPATH += "C:\opencv_build\install\include"

DEPENDPATH += "C:\opencv_build\install\include"
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
