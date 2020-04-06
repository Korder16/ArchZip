#ifndef IMAGE_FILE_OPERATOR_H
#define IMAGE_FILE_OPERATOR_H

#include "ifile_operator.h"

class ImageFileOperator : public IFileOperator {
public:
    explicit ImageFileOperator();
    ~ImageFileOperator();

    QList<Pixel> read_file(const QString &filename) override;

    QList<Pixel> fill_pixel_list(const QImage* img);

    void write_file(const QString& filename, const QList<PixelInfo>& data) override;

    void fill_file(QIODevice* file, const QList<PixelInfo>& data);
};

#endif // IMAGE_FILE_OPERATOR_H
