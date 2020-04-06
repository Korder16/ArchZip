#ifndef ICOMPRESSOR_H
#define ICOMPRESSOR_H

#include <QList>
#include <QTime>
#include <QColor>
#include <QImage>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QElapsedTimer>

#include "pixel_info.h"
#include "ifile_operator.h"
#include "image_file_operator.h"
#include "compression_info.h"
#include <iostream>


class ICompressor : public QObject {
    Q_OBJECT
public:
    ICompressor();
    virtual ~ICompressor();

    void compress_file(const QString& filename);

    void save_compressed_picture(const QString& filename, const QList<PixelInfo>& compressed_data);

private:
    virtual QList<PixelInfo> compress_data(const QList<Pixel>& file_data) = 0;

    IFileOperator* img_file_op{new ImageFileOperator()};

signals:
    void compression_finished(const CompressionInfo& compression_info);
};

#endif // ICOMPRESSOR_H
