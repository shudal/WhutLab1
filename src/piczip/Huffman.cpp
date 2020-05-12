//
// Created by perci on 2020/5/12.
//

#include "Huffman.h"
#include <limits>

int Huffman::getMinWeightIndex (int to) {
    int min_index = -1;
    int min_weight = std::numeric_limits<int>::max();
    for (auto i=0; i<=to; ++i) {
        if (vs_[i].f == 0) {
            if (vs_[i].w <= min_weight) {
                min_weight = vs_[i].w;
                min_index = i;
            }
        }
    }
    if (min_index == -1) {
        throw "invalid min index";
    }
    return min_index;
};
std::vector<Node> Huffman::constructTree (std::vector<int> weight) {
    status_ = false;
    auto n = weight.size();
    if (n < 2) {
        return vs_;
    }
    auto n2 = n * 2 - 1;
    vs_.resize(n2);
    for (auto i=0; i<n; ++i) {
        vs_[i] = Node(weight[i]);
    }
    for (auto i=n; i < n2; ++i) {
        int l = getMinWeightIndex(i-1);
        vs_[i].l = l;
        vs_[l].f = i;

        int r = getMinWeightIndex(i-1);
        vs_[i].r = r;
        vs_[r].f = i;

        vs_[i].w = vs_[l].w + vs_[r].w;
    }

    status_ = true;
    return vs_;
}
std::vector<std::string> Huffman::encode(std::vector<Node> vns) {
    status_ = false;
    std::vector<std::string> ans;

    int n2 = vns.size();

    // n2为奇数
    if (n2 < 3 || (n2 % 2 != 1)) {
        return ans;
    }
    int n = (n2 + 1) / 2;

    vs_ = std::move(vns);
    now_code = "";
    codes_.resize(n);
    // dfs
    dfs(vs_[n2 - 1], n2 - 1);

    ans = std::move(codes_);
    status_ = true;
    return ans;
}
void Huffman::dfs(Node head, int index) {
    int l = head.l;
    int r = head.r;

    if (l == -1 && r == -1) {
        std::string s (now_code);
        codes_[index] = s;
    }

    if (l != -1) {
        now_code.push_back(left_value_);
        dfs(vs_[l], l);
        now_code.pop_back();
    }
    if (r != -1) {
        now_code.push_back(right_value_);
        dfs(vs_[r], r);
        now_code.pop_back();
    }
}