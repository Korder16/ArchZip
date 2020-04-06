#ifndef COMPRESSION_INFO_H
#define COMPRESSION_INFO_H

#include <QString>

struct CompressionInfo {
    CompressionInfo(const QString& filename, const QString& current_time,
                    const QString& algorithm, int time_elapsed,
                    size_t img_size, size_t compressed_img_size);

    QString _filename;              // Filename
    QString _current_time;          // Time of compression
    QString _algorithm;             // Compression algorithm
    int _time_elapsed;              // Compression time elapsed
    size_t _img_size;               // Input image size
    size_t _compressed_img_size;    // Compressed image size
};

#endif // COMPRESSION_INFO_H
