#include <QList>
#include <QImage>
#include <QColor>
#include <QDebug>
#include <QObject>
#include <QCoreApplication>

#include "icompressor.h"
#include "rle_compressor.h"
#include "huffman_compressor.h"
#include "config_reader.h"
#include "ilogger.h"
#include "compression_logger.h"

#include <memory>
#include <iostream>

int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);

    // Read config file
    QString config_name = ":/config/config/settings.conf";
    ConfigReader::get_instance().read_config(config_name);

    ILogger* logger = new CompressionLogger();
    ICompressor* rle_compressor = new RLECompressor();
    QObject::connect(rle_compressor, SIGNAL(compression_finished(const CompressionInfo&)),
                     logger, SLOT(write_compression_log(const CompressionInfo&)));

    QString files_to_compress_dir = ConfigReader::get_instance().get_config_setting("files_to_compress_dir");
//    QString picture_name = "red_square.jpg";
    QString picture_name = "blue_rect.png";
//    QString picture_name = "figures.jpg";

    rle_compressor->compress_file(files_to_compress_dir + picture_name);

    delete rle_compressor;
    delete logger;


    HuffmanCompressor* huffman_compressor = new HuffmanCompressor();
    ImageFileOperator* fo = new ImageFileOperator();

    QList<Pixel> list = fo->read_file(files_to_compress_dir + picture_name);
    huffman_compressor->huffman_codes(list);

    delete fo;
    delete huffman_compressor;

    return 0;
}
