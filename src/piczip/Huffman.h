//
// Created by perci on 2020/5/12.
//

#ifndef UNTITLED1_HUFFMAN_H
#define UNTITLED1_HUFFMAN_H

#include <vector>
#include <string>
#include <list>
class Node {
public:
    int w;
    int f;
    int l;
    int r;
    Node () {
        f = 0;
        l = -1;
        r = -1;
    }
    Node (int _w) : w(_w) {
        f = 0;
        l = -1;
        r = -1;
    }
};
class Huffman {
private:
    std::vector<Node> vs_;
    int getMinWeightIndex (int);
    bool status_ = false;

    // 给dfs用
    std::string now_code;
    std::vector<std::string> codes_;
    // 左子树为1，右子树为0
    char left_value_ = '1';
    char right_value_ = '0';
    void dfs(Node, int);
public:
    // weight是index->w
    std::vector<Node> constructTree (std::vector<int> weight);
    std::vector<std::string> encode(std::vector<Node>);
    bool getStatus () { return status_ ;}
};


#endif //UNTITLED1_HUFFMAN_H
