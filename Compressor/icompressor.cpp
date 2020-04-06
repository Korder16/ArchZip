#include <QDebug>

#include "icompressor.h"
#include "config_reader.h"
#define TIME_DEBUG

ICompressor::ICompressor() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ICompressor::~ICompressor() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete img_file_op;
}


void ICompressor::compress_file(const QString &filename) {
    // Openning picture
    QList<Pixel> img_data = img_file_op->read_file(filename);

    std::cout << "Input data size = " << img_data.size() << std::endl;


    QElapsedTimer timer;
    timer.start();

    QList<PixelInfo> compressed_data = compress_data(img_data);

    size_t compression_ratio = img_data.size() / compressed_data.size();
    std::cout << "Compression ratio = " << compression_ratio << std::endl;

    qint64 timer_elapsed = timer.elapsed();
#ifdef TIME_DEBUG
    std::cout << "Time = " << timer_elapsed << " ms" << std::endl;
#endif

    QString compressed_files_dir = ConfigReader::get_instance().get_config_setting("compressed_files_dir");
    QString zipped_filename = filename.split("/").last() + ".tar";
    save_compressed_picture(compressed_files_dir + zipped_filename, compressed_data);

    CompressionInfo info(filename,
                         QTime::currentTime().toString("hh-mm-ss"),
                         "rle",
                         timer_elapsed,
                         img_data.size(),
                         compressed_data.size()
                         );

    emit compression_finished(info);
}


void ICompressor::save_compressed_picture(const QString& filename, const QList<PixelInfo> &compressed_data) {
    img_file_op->write_file(filename, compressed_data);
}
