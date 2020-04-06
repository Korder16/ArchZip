#include "huffman_compressor.h"
#include <QDebug>
HuffmanCompressor::HuffmanCompressor() : ICompressor() {}

HuffmanCompressor::~HuffmanCompressor() {}

QList<PixelInfo> HuffmanCompressor::compress_data(const QList<Pixel> &file_data) {
//    huffman_codes(file_data);
}


void HuffmanCompressor::print_codes(HuffmanNode *root, const QString& str) {
    if(root == nullptr) {
        return;
    }

    if(root->_pixel != '$') {
        std::cout << root->_pixel << ": " << str.toStdString() << std::endl;
    }

    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}


void HuffmanCompressor::huffman_codes(const QList<Pixel>& list_of_pixels) {
    struct HuffmanNode  *left{nullptr},
                        *right{nullptr},
                        *top{nullptr};

    QMap<Pixel, int> map_of_pixel = count_repeating_pixels(list_of_pixels);

    // Create a min heap & inserts all characters of data[]
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare> min_heap;

    QMap<Pixel, int>::iterator it = map_of_pixel.begin();

    for(it; it != map_of_pixel.end(); ++it) {
        min_heap.push(new HuffmanNode(it.key()._pixel, it.value()));
    }

    // Iterate while size of heap doesn't become 1
    while(min_heap.size() != 1) {
        // Extract the two minimum
        // freq items from min heap
        left = min_heap.top();
        min_heap.pop();

        right = min_heap.top();
        min_heap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new HuffmanNode('$', left->_freq + right->_freq);

        top->left = left;
        top->right = right;

        min_heap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    print_codes(min_heap.top(), "");
}


QMap<Pixel, int> HuffmanCompressor::count_repeating_pixels(const QList<Pixel>& list_of_pixels) {
    std::map<Pixel, int> map_pixel;

    for(int i = 0; i < list_of_pixels.size(); ++i) {
        map_pixel[list_of_pixels.at(i)]++;
    }

    QMap<Pixel, int> result_map(map_pixel);
    return result_map;
}
