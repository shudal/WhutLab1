//
// Created by perci on 2020/5/12.
//

#include "gtest/gtest.h"
#include "../../piczip/Huffman.h"

TEST(piczip, Huffman) {
    Huffman h;
    std::vector<int> vs = {10,7,15,31};
    std::vector<Node> v2 = h.constructTree(vs);
    EXPECT_EQ(v2[0].f, v2[1].f);
    EXPECT_EQ(v2[v2[0].f].f, v2[2].f);
    std::vector<std::string> codes_ = h.encode(v2);
    EXPECT_EQ(codes_.size(), vs.size());
}
