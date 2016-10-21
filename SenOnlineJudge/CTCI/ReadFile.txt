CONFIG  -= classifier
CONFIG  += calibration
CONFIG  -= merging
CONFIG  -= autoscantodisk
CONFIG  -= pointcloudlibrary
CONFIG  -= realsense
CONFIG  -= prosilica
CONFIG  -= primesense
CONFIG  -= vimba
CONFIG  -= kinect
CONFIG  += cassi

QT      += core gui widgets opengl serialport network

TEMPLATE = app

SOURCES += main.cpp \
           Filters/laudftfilter.cpp \
           Filters/lauoptitraxfilter.cpp \
           Filters/lauabstractfilter.cpp \
           Filters/laumedianglfilter.cpp \
           Filters/lauentropyglfilter.cpp \
           Filters/lauresampleglfilter.cpp \
           Filters/lausavetodiskfilter.cpp \
           Filters/lauvoxelmapglfilter.cpp \
           Filters/lauproximityglfilter.cpp \
           Filters/laubilateralglfilter.cpp \
           Filters/laucurvatureglfilter.cpp \
           Filters/laumagicwandglfilter.cpp \
           Filters/laubackgroundglfilter.cpp \
           Filters/lauframefocusglfilter.cpp \
           Filters/laugreenscreenglfilter.cpp \
           Filters/laufitcylinderglfilter.cpp \
           Filters/lauopticalflowglfilter.cpp \
           Filters/lauframeaveragingfilter.cpp \
           Filters/laugriddetectorglfilter.cpp \
           Filters/lausliprojectorglfilter.cpp \
           Filters/lausurfacenormalglfilter.cpp \
           Filters/laustrainanalysisglfilter.cpp \
           Filters/laualphatrimmedmeanglfilter.cpp \
           Filters/laugreenscreenwithmagicwandglfilter.cpp \
           Sinks/lau3dvideocalibrationwidget.cpp \
           Sinks/lau3dvideorecordingwidget.cpp \
           Sinks/lau3dfiducialglwidget.cpp \
           Sinks/lau3dvideoplayerwidget.cpp \
           Sinks/lau3dvideoglwidget.cpp \
           Sinks/lau3dscanglwidget.cpp \
           Sinks/lau3dmultiscanglwidget.cpp \
           Sinks/lau3dvideowidget.cpp \
           Sources/lau3dcamera.cpp \
           Support/lauvideoplayerlabel.cpp \
           Support/lauscaninspector.cpp \
           Support/laumemoryobject.cpp \
           Support/laulookuptable.cpp \
           Support/lauglwidget.cpp \
           Support/lauscan.cpp \
           User/laudocument.cpp \
           User/laumenuwidget.cpp \
           User/laudocumentwidget.cpp

HEADERS += Filters/laudftfilter.h \
           Filters/lauoptitraxfilter.h \
           Filters/lauabstractfilter.h \
           Filters/laumedianglfilter.h \
           Filters/lauentropyglfilter.h \
           Filters/lauresampleglfilter.h \
           Filters/lausavetodiskfilter.h \
           Filters/lauvoxelmapglfilter.h \
           Filters/lauproximityglfilter.h \
           Filters/laubilateralglfilter.h \
           Filters/laucurvatureglfilter.h \
           Filters/laumagicwandglfilter.h \
           Filters/laubackgroundglfilter.h \
           Filters/lauframefocusglfilter.h \
           Filters/laugreenscreenglfilter.h \
           Filters/lauopticalflowglfilter.h \
           Filters/laufitcylinderglfilter.h \
           Filters/lauframeaveragingfilter.h \
           Filters/laugriddetectorglfilter.h \
           Filters/lausliprojectorglfilter.h \
           Filters/lausurfacenormalglfilter.h \
           Filters/laustrainanalysisglfilter.h \
           Filters/laualphatrimmedmeanglfilter.h \
           Filters/laugreenscreenwithmagicwandglfilter.h \
           Sinks/lau3dvideocalibrationwidget.h \
           Sinks/lau3dvideorecordingwidget.h \
           Sinks/lau3dvideoplayerwidget.h \
           Sinks/lau3dmultiscanglwidget.h \
           Sinks/lau3dfiducialglwidget.h \
           Sinks/lau3dvideoglwidget.h \
           Sinks/lau3dscanglwidget.h \
           Sinks/lau3dvideowidget.h \
           Sources/lau3dcamera.h \
           Support/lauvideoplayerlabel.h \
           Support/lauscaninspector.h \
           Support/laumemoryobject.h \
           Support/laulookuptable.h \
           Support/laucontroller.h \
           Support/lauglwidget.h \
           Support/lauscan.h \
           User/laudocument.h \
           User/laumenuwidget.h \
           User/laudocumentwidget.h

RESOURCES += Images/lauvideoplayerlabel.qrc \
             Images/merging.qrc \
             Shaders/shaders.qrc

OTHER_FILES    += ToDoList.txt
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

INCLUDEPATH += $$PWD/BCS $$PWD/Calibration $$PWD/Classifiers $$PWD/Filters $$PWD/Merge $$PWD/Sources $$PWD/Processing $$PWD/Sinks $$PWD/Support $$PWD/User $$PWD/Velmex

merging {
    DEFINES += ENABLEPOINTMATCHER
    HEADERS += BCS/lau3dsymmetryfilter.h \
               BCS/lau3dbcstrackingwidget.h \
               BCS/laubcsbatchprocesswidget.h \
               BCS/lau3dcowlabelingglfilter.h \
               BCS/lau3dbcstrackingfilter.h \
               BCS/lautaildetectorfilter.h \
               BCS/laucowdetectorfilter.h \
               BCS/lau3dsymmetrywidget.h \
               Merge/lau3dtrackingwidget.h \
               Merge/lau3dtrackingfilter.h \
               Merge/lauiterativeclosestpointobject.h \
               Merge/laumergescanwidget.h \
               Merge/lauplyobject.h \
               Merge/lauplyglwidget.h
    SOURCES += BCS/lau3dsymmetryfilter.cpp \
               BCS/lau3dbcstrackingfilter.cpp \
               BCS/laubcsbatchprocesswidget.cpp \
               BCS/lau3dcowlabelingglfilter.cpp \
               BCS/lau3dbcstrackingwidget.cpp \
               BCS/lautaildetectorfilter.cpp \
               BCS/laucowdetectorfilter.cpp \
               BCS/lau3dsymmetrywidget.cpp \
               Merge/lau3dtrackingwidget.cpp \
               Merge/lau3dtrackingfilter.cpp \
               Merge/lauiterativeclosestpointobject.cpp \
               Merge/laumergescanwidget.cpp \
               Merge/lauplyobject.cpp \
               Merge/lauplyglwidget.cpp
}

pointcloudlibrary {
    DEFINES += ENABLEPOINTCLOUDLIBRARY
}

autoscantodisk {
    DEFINES += ENABLEAUTOSCANTODISK
}

classifier {
    DEFINES   += ENABLECLASSIFIER
    HEADERS   += Classifiers/laumachinelearningobject.h \
                 Classifiers/lauclassifywidget.h
    SOURCES   += Classifiers/laumachinelearningobject.cpp \
                 Classifiers/lauclassifywidget.cpp
    RESOURCES += Classifiers/classifiers.qrc
}

calibration {
    DEFINES   += ENABLECALIBRATION
    HEADERS   += Calibration/lau3dcaltagglfilter.h \
                 Calibration/lau3dcalibrationbinarizeglfilter.h \
                 Calibration/lau3dcalibrationwidget.h \
                 Calibration/lau3dcalibrationglfilter.h \
                 Calibration/lau3droundgridglfilter.h \
                 Calibration/lau3dexposureglfilter.h \
                 Velmex/lauvelmexwidget.h

    SOURCES   += Calibration/lau3dcaltagglfilter.cpp \
                 Calibration/lau3dcalibrationbinarizeglfilter.cpp \
                 Calibration/lau3dcalibrationwidget.cpp \
                 Calibration/lau3dcalibrationglfilter.cpp \
                 Calibration/lau3droundgridglfilter.cpp \
                 Calibration/lau3dexposureglfilter.cpp \
                 Velmex/lauvelmexwidget.cpp
}

cassi {
    DEFINES += CASSI
    HEADERS += CASSI/cassi.h \
               CASSI/laucassiframeaveragingglfilter.h
    SOURCES += CASSI/laucassiframeaveragingglfilter.cpp
    INCLUDEPATH += $$PWD/CASSI
}

unix {
    QMAKE_CXXFLAGS += -msse2 -msse3 -mssse3 -msse4.1
    ICON            = Images/LauIcon.icns
    INCLUDEPATH    += /usr/local/include /usr/local/include/eigen3
    DEPENDPATH     += /usr/local/include /usr/local/include/eigen3
    LIBS           += /usr/local/lib/libtiff.5.dylib

    primesense {
        TARGET         = LAUPrimeSense
        DEFINES       += PRIMESENSE
        LIBS          += -L/usr/local/lib/ni2/ -lOpenNI2
        INCLUDEPATH   +=   /usr/local/include/ni2
        DEPENDPATH    +=   /usr/local/include/ni2
        HEADERS       += Sources/lauprimesensecamera.h
        SOURCES       += Sources/lauprimesensecamera.cpp
    }

    prosilica {
        TARGET         = LAUProsilica
        QT            += network
        DEFINES       += PROSILICA _OSX _x64
        INCLUDEPATH   +=   $$PWD/AVTGigESDK/inc-pc
        DEPENDPATH    +=   $$PWD/AVTGigESDK/inc-pc
        LIBS          += -L$$PWD/AVTGigESDK/bin-pc/x64/ -lPvAPI
        HEADERS       += Sources/lauprosilicacamera.h \
                         Sources/lau3dseikowavescannerwidget.h
        SOURCES       += Sources/lauprosilicacamera.cpp
    }

    merging {
        CONFIG        += c++11
        INCLUDEPATH   += /usr/local/include/pointmatcher
        DEPENDPATH    += /usr/local/include/pointmatcher
        LIBS          += -framework CoreFoundation -L/usr/local/lib -lpointmatcher -lnabo -lyaml-cpp-pm -lboost_system-mt
    }

1
2
3
4
5
6
7
8
9
10