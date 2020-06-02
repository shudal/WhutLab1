//
// Created by perci on 2020/6/2.
//

#ifndef UNTITLED2__MYGRAPH_H_
#define UNTITLED2__MYGRAPH_H_

#include <string>
#include <vector>

class Node {
 public:
  int id;
  std::string name;
  std::string des;
  Node() = default;
  Node(int _id, std::string _n, std::string _des) : id(_id), name(_n), des(_des) {}
};
class MyGraph {
 private:
  const int max_line_char = 4000;
  std::string file_src_vex_;
  std::string file_src_edge_;
  std::vector<std::vector<std::pair<int,int>>> edges;
  std::vector<Node> nodes;
  std::vector<int> dfs_vis;
  std::vector<std::vector<int>> paths;
  void insertEdge(int, int, int);
  void printGraph();
  void dfs(int, std::vector<int>&);
 public:
  void printVex(int);
  void printVexs();
  void init(std::string, std::string);
  void dfsTravel(int);
  void finMinPath(int,int);
  void prime();
};
#endif//UNTITLED2__MYGRAPH_H_
