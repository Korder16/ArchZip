#ifndef FRACTALCOMPRESSOR_H
#define FRACTALCOMPRESSOR_H
#include "icompressor.h"

class FractalCompressor : public ICompressor {
public:
    explicit FractalCompressor();
    ~FractalCompressor();

    QList<PixelInfo> compress_data(const QList<Pixel>& file_data) override;
};

#endif // FRACTALCOMPRESSOR_H
