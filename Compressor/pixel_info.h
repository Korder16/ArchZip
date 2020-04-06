#ifndef PIXEL_INFO_H
#define PIXEL_INFO_H

#include <QColor>
#include <QImage>

struct Pixel {
    Pixel(const QRgb& pixel);
    QRgb _pixel;
};

bool operator ==(const Pixel& first_pix, const Pixel& second_pix);
bool operator < (const Pixel& first_pix, const Pixel& second_pix);

class PixelInfo : private Pixel {
public:
    PixelInfo();
    PixelInfo(const Pixel& pixel, int freq);

    QRgb get_pixel() const;
    int get_freq() const;

private:
    int _freq;
};


#endif // PIXEL_INFO_H
