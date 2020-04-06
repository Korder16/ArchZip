#include "pixel_info.h"

Pixel::Pixel(const QRgb &pixel) : _pixel(pixel) {}

bool operator ==(const Pixel& first_pix, const Pixel& second_pix) {
    if(first_pix._pixel == second_pix._pixel)
        return true;
    else
        return false;
}

bool operator < (const Pixel& first_pix, const Pixel& second_pix) {
    if(first_pix._pixel < second_pix._pixel) {
        return true;
    }
    else {
        return false;
    }
}

PixelInfo::PixelInfo(const Pixel& pixel, int freq) :
    Pixel(pixel),
    _freq(freq)
{}

QRgb PixelInfo::get_pixel() const {
    return _pixel;
}

int PixelInfo::get_freq() const {
    return _freq;
}
