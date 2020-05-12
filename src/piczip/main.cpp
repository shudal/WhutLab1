//
// Created by perci on 2020/5/12.
//

#include "PhotoCompressionByHuffman.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::string file_src = "1.jpg";
    std::cout << "输入图片路径：";
    std::cin >> file_src;
    PhotoCompressionByHuffman c(file_src);
    c.compress();
    return 0;
}

