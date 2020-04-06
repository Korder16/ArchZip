#include "compression_info.h"

CompressionInfo::CompressionInfo(const QString &filename, const QString &current_time,
                                 const QString &algorithm, int time_elapsed,
                                 size_t img_size, size_t compressed_img_size) :
    _filename(filename),
    _current_time(current_time),
    _algorithm(algorithm),
    _time_elapsed(time_elapsed),
    _img_size(img_size),
    _compressed_img_size(compressed_img_size) {}

