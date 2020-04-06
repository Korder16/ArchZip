#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include "icompressor.h"
#include <queue>
#include <vector>
#include <qiterator.h>
#include <QSet>
struct HuffmanNode {
    // 8 bytes
    HuffmanNode* left{nullptr};
    HuffmanNode* right{nullptr};

    // 4 bytes
    int _freq;

    QRgb _pixel;

    HuffmanNode(const QRgb& pixel, int freq) {
        left = right = nullptr;
        this->_pixel = pixel;
        this->_freq = freq;
    }

};

// Comparison 2 heap nodes
struct compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return (left->_freq > right->_freq);
    }
};

class HuffmanCompressor : public ICompressor {

public:
    explicit HuffmanCompressor();
    ~HuffmanCompressor();

    QList<PixelInfo> compress_data(const QList<Pixel>& file_data) override;


    void huffman_codes(const QList<Pixel>& list_of_pixels);

private:
    HuffmanNode* node_array[128];

    QMap<Pixel, int> count_repeating_pixels(const QList<Pixel>& list_of_pixels);
    void print_codes(struct HuffmanNode* root, const QString& str);
};

#endif // HUFFMANCOMPRESSOR_H
