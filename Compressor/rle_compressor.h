#ifndef RLECOMPRESSOR_H
#define RLECOMPRESSOR_H
#include "icompressor.h"

class RLECompressor : public ICompressor {
public:
    explicit RLECompressor();
    ~RLECompressor();

    QList<PixelInfo> compress_data(const QList<Pixel>& file_data) override;
};

#endif // RLECOMPRESSOR_H
