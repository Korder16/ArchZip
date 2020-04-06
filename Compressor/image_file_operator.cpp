#include "image_file_operator.h"

ImageFileOperator::ImageFileOperator() {}

ImageFileOperator::~ImageFileOperator() {}

QList<Pixel> ImageFileOperator::read_file(const QString &filename) {
    if(!QFile::exists(filename)) {
        std::cerr << "Error while openning " << filename.toStdString() << std::endl;
        return QList<Pixel>();
    }
    else {
        QList<Pixel> pixel_list;
        QImage* img = new QImage(filename);

        // File pixel_list with pixels
        pixel_list = fill_pixel_list(img);

        delete img;
        return pixel_list;
    }
}

void ImageFileOperator::write_file(const QString &filename, const QList<PixelInfo> &data) {
    QFile* file = new QFile(filename);
    if(file->open(QIODevice::WriteOnly)) {
        fill_file(file, data);
    }
    else {
        delete file;
        return;
    }
    delete file;
}


QList<Pixel> ImageFileOperator::fill_pixel_list(const QImage *img) {
    QList<Pixel> pixel_list;
    // Count size of image
    size_t data_size = img->size().width() * img->size().height();
    pixel_list.reserve(data_size);

    // Fill list
    for(int i = 0; i < img->size().width(); ++i) {
        for(int j = 0; j < img->size().height(); ++j) {
            pixel_list.append(img->pixel(i, j));
        }
    }
    return pixel_list;
}


void ImageFileOperator::fill_file(QIODevice *file, const QList<PixelInfo> &data) {
    QDataStream in(file);
    for(int i = 0; i < data.size(); ++i) {
        in << data.at(i).get_pixel() << data.at(i).get_freq();
    }
}
