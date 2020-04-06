QT += gui

CONFIG += c++11
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -O2

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        fractal_compressor.cpp \
        huffman_compressor.cpp \
        icompressor.cpp \
        ifile_operator.cpp \
        ilogger.cpp \
        main.cpp \
        rle_compressor.cpp \
    time_counter.cpp \
    pixel_info.cpp \
    image_file_operator.cpp \
    config_reader.cpp \
    compression_logger.cpp \
    compression_info.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    fractal_compressor.h \
    huffman_compressor.h \
    icompressor.h \
    ifile_operator.h \
    ilogger.h \
    rle_compressor.h \
    time_counter.h \
    pixel_info.h \
    image_file_operator.h \
    config_reader.h \
    compression_logger.h \
    compression_info.h

RESOURCES += \
    resource.qrc
