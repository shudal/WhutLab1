//
// Created by perci on 2020/5/12.
//

#include <iostream>
#include <vector>
#include "Huffman.h"
#include "PhotoCompressionByHuffman.h"
#include <cstdio>
std::vector<unsigned char> PhotoCompressionByHuffman:: compress () {
    int result = 0;
    std::vector<unsigned char> chars;
    std::ifstream file_buffer;
    file_buffer.open(file_src_, std::ios::in | std::ios::binary);
    if (file_buffer.is_open()) {
        file_buffer.seekg(0, std::ios::end);
        length_ = file_buffer.tellg();
        if (debug) {
            std::cout<<"原始字节数："<<length_<<std::endl;
        }

        file_buffer.seekg(0, std::ios::beg);
        chars.resize(length_);
        file_buffer.read (reinterpret_cast<char*>(chars.data()), length_);
        file_buffer.close();

        std::vector<int> weight(x1_);
        for (int i=0; i<length_; ++i) {
            int index = static_cast<int> (chars[i]);
            weight [index] ++;
        }

        if (debug) {
            for (auto i=0; i<=255; i++) {
                printf("0x%02x ",i);
                std::cout<<weight[i]<<std::endl;
            }
        }

        std::vector<Node> vn = h.constructTree(weight);

        if (debug) {
                printf("Byte         left  right  weight\n");
            for (auto i=0; i<vn.size(); i++) {
                printf("pHT[%03d]    %03d    %03d     %d\n", i + 1, vn[i].l, vn[i].r, vn[i].w);

            }
        }

        std::vector<std::string> codes_ = h.encode(vn);

        if (debug) {
            printf ("Byte Code\n");
            for (int i=0; i<codes_.size(); i++) {
                printf("0x%02x    ", i);
                std::cout<<codes_[i]<<std::endl;
            }
        }

        std::list<char> buffer;
        std::vector<unsigned char> final_chars;

        if (debug) {
            std::cout<<"压缩后的编码："<<std::endl;
        }
        for (auto i=0; i<chars.size(); ++i) {
            int index = static_cast<int> (chars[i]);
            std::string s = codes_[index];
            if (debug) {
                std::cout<<s;
            }
            for (auto it=s.cbegin(); it != s.cend(); ++it) {
                buffer.push_back(*it);
            }
            while (buffer.size() >= 8) {
                unsigned char x3 = 0;
                for (auto k=0; k<8; k++) {
                    char c2 = buffer.front();
                    buffer.pop_front();
                    if (c2 == '1') {
                        x3 += 1;
                    }
                    x3 = x3 << 1;
                }
                final_chars.push_back(x3);
            }
        }
       if (buffer.size() > 0) {
            unsigned char x3 = 0;
            for (auto k=0; k < 8; k++) {
                char c2;
                if (buffer.empty()) {
                    c2 = '0';
                } else {
                    c2 = buffer.front();
                    buffer.pop_front();
                }
                if (c2 == '1') {
                    x3 += 1;
                }
                x3 = x3 << 1;
            }
            final_chars.push_back(x3);
        }
        std::ofstream output_buffer(file_src_ + ".huf", std::ios::out | std::ios::binary);
        char* c5 = reinterpret_cast<char*>(final_chars.data());
        std::cout<<"压缩后字节数："<<final_chars.size()<<std::endl;
        std::cout<<"压缩比例："<<(1.0*final_chars.size()/length_);
        output_buffer.write(c5,final_chars.size());
        output_buffer.close();

    } else {
        result = 1;
    }

    result_status_ = result;
    return chars;
}

char PhotoCompressionByHuffman::binString2Char(std::string s) {
    int x = 0;
    for (auto i=7; i>=0; --i) {

    }
    return 0;
}
