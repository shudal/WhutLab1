//
// Created by perci on 2020/5/12.
//

#ifndef UNTITLED1_PHOTOCOMPRESSIONBYHUFFMAN_H
#define UNTITLED1_PHOTOCOMPRESSIONBYHUFFMAN_H

#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include "Huffman.h"

class PhotoCompressionByHuffman {
private:
    int x1_ = 256;
    Huffman h;
    char binString2Char(std::string);
    bool debug = true;
public:
    std::string file_src_;
    int length_;
    int result_status_;
    PhotoCompressionByHuffman (std::string _src) : file_src_(_src) {
        length_ = -1;
    }
    std::vector<unsigned char> compress ();

};
#endif //UNTITLED1_PHOTOCOMPRESSIONBYHUFFMAN_H
