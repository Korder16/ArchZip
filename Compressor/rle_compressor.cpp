#include "rle_compressor.h"

RLECompressor::RLECompressor() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

RLECompressor::~RLECompressor() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

QList<PixelInfo> RLECompressor::compress_data(const QList<Pixel> &file_data) {
    QList<PixelInfo> compressed_data;
    int list_size = file_data.size();

    for(int i = 0; i < list_size; ++i) {
        int count{1};
        while(i < list_size - 1 && (file_data.at(i) == file_data.at(i + 1))) {
            ++count;
            ++i;
        }
        PixelInfo pixel_info(file_data.at(i), count);
        compressed_data.append(pixel_info);
    }
    std::cout << "Compressed data size = " << compressed_data.size() << std::endl;
    return compressed_data;
}

