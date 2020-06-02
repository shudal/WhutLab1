//
// Created by perci on 2020/6/2.
//

#include "MyGraph.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <cstdio>
#include <queue>
#include <stack>
void MyGraph::init(std::string file_src_vex, std::string file_src_edge) {
  file_src_vex_ = file_src_vex;
  file_src_edge_ = file_src_edge;

  std::thread t1([&]{
    std::ifstream vex_file_buffer;
    vex_file_buffer.open(file_src_vex_, std::ios::in);
    if (vex_file_buffer.is_open()) {
      int node_count;
      vex_file_buffer>>node_count;
      for (int i=0; i<node_count; i++) {
        Node node;
        vex_file_buffer>>node.id;
        vex_file_buffer>>node.name;
        vex_file_buffer>>node.des;
        nodes.push_back(node);
      }
    }
  });

  std::thread t2([&]{
    std::ifstream edge_file_buffer;
    edge_file_buffer.open(file_src_edge_, std::ios::in);
    if (edge_file_buffer.is_open()) {
      int from, to, dis;
      while (edge_file_buffer>>from && !edge_file_buffer.eof()) {
        edge_file_buffer>>to;
        edge_file_buffer>>dis;
        insertEdge(from,to, dis);
        insertEdge(to, from, dis);
      }
    }
  });
  t1.join(); t2.join();
  printGraph();
}
void MyGraph::insertEdge(int from, int to, int dis) {
  if (from >= edges.size()) {
    edges.resize(from + 1);
  }
  for (auto i : edges[from]) {
    if (i.first == to) {
      return;
    }
  }
  edges[from].push_back({to, dis});
}
void MyGraph::printGraph() {
  std::cout<<"===== 创建景区景点图 ====="<<std::endl;
  std::cout<<"顶点数目:"<<nodes.size()<<std::endl;
  std::cout<<"----- 顶点 -----"<<std::endl;
  printVexs();
  std::cout<<"----- 边 -----"<<std::endl;
  for (int i=0; i<edges.size(); i++) {
    for (auto p : edges[i]) {
      if (i < p.first) {
        printf("<v%d, v%d> %d\n", i, p.first, p.second);
      }
    }
  }
}
void MyGraph::printVexs() {
  for (auto node : nodes) {
    std::cout<<node.id<<"-"<<node.name<<std::endl;
  }
}
void MyGraph::printVex(int i) {
  if (i<nodes.size()) {
    std::cout<<nodes[i].name<<std::endl;
    std::cout<<nodes[i].des<<std::endl;
    std::cout<<"----- 周边景区 ------"<<std::endl;
    for (auto p : edges[i]) {
      std::cout<<nodes[i].name<<"->"<<nodes[p.first].name<<" "<<p.second<<"m"<<std::endl;
    }
  } else {
    std::cout<<"编号不正确\n"<<std::endl;
  }
}
void MyGraph::dfs(int vexi, std::vector<int> & al_path) {
  al_path.push_back(vexi);
  dfs_vis[vexi] = true;
  for (auto p : edges[vexi]) {
    if (dfs_vis[p.first]) {
      continue;
    } else {
      dfs(p.first, al_path);
    }
  }
  if (al_path.size() == nodes.size()) {
    paths.push_back(al_path);
  }
  dfs_vis[vexi] = false;
  al_path.pop_back();
}
void MyGraph::dfsTravel(int vexi) {
  dfs_vis.clear();
  dfs_vis.resize(nodes.size());

  paths.clear();
  if (vexi < nodes.size()) {
    std::vector<int> vs;
    dfs(vexi, vs);
    std::cout<<"导航路线为:\n";
    for (int i=1; i<= paths.size(); i++) {
      std::vector<int> & path = paths[i-1];
      printf("路线%d: %s ", i, nodes[path[0]].name.c_str());
      for (int k=1; k<path.size(); k++) {
        printf("-> %s", nodes[path[k]].name.c_str());
      }
      std::cout<<std::endl;
    }
  } else {
    std::cout<<"编号不正确\n"<<std::endl;
  }
}
void MyGraph::finMinPath(int from, int to) {
  if (!(from < nodes.size() && to < nodes.size())) {
    std::cout<<"编号非法\n";
    return;
  }

  std::queue<int> q;
  q.push(from);
  std::vector<int> pre (nodes.size(), 0);
  std::vector<int> vis(nodes.size(), 0);
  std::vector<int> dis (nodes.size(), INT32_MAX);
  dis[from] = 0;
  vis[from] = 1;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    vis[x] = 0;
    for (auto to_p : edges[x]) {
      int toi = to_p.first;
      int cost = to_p.second;

      if (dis[x] + cost < dis[toi]) {
        dis[toi] = dis[x] + cost;
        pre[toi] = x;

        if (vis[toi]) continue;
        q.push(toi);
        vis[toi] = 1;
      }
    }
  }
  std::cout<<"最短路线为："<<nodes[from].name;
  std::stack<int> stk;
  int tmp = to;
  while (pre[tmp] != from) {
    stk.push(pre[tmp]);
    tmp = pre[tmp];
  }
  while (!stk.empty()) {
    int x = stk.top();
    stk.pop();
    printf("->%s", nodes[x].name.c_str());
  }
  printf("->%s\n", nodes[to].name.c_str());
  printf("最短距离为: %d\n", dis[to]);
}
void MyGraph::prime() {
  int sum = 0;
  int init_x = 0;
  std::vector<int> lowcost(nodes.size(), INT32_MAX);
  std::vector<int> mst(nodes.size(), -1);
  for (auto p : edges[init_x]) {
    lowcost[p.first] = p.second;
    mst[p.first] = init_x;
  }
  lowcost[init_x] = -1;

  int n = nodes.size();

  // 执行n-1次
  for (int count_i=1; count_i<n; count_i++) {
    int min_dis = INT32_MAX;
    int min_index = 0;
    for (int i=0; i<n; i++) {
      if (lowcost[i] < min_dis && lowcost[i] != -1) {
        min_dis = lowcost[i];
        min_index = i;
      }
    }
    sum += min_dis;
    lowcost[min_index] = -1;

    for (auto p : edges[min_index]) {
      if (lowcost[p.first] > p.second) {
        lowcost[p.first] = p.second;
        mst[p.first] = min_index;
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (mst[i] != -1) {
      int cost = -1;
      for (auto p : edges[i]) {
        if (p.first == mst[i]) {
          cost = p.second;
          break;
        }
      }
      printf("%s - %s %dm\n", nodes[i].name.c_str(), nodes[mst[i]].name.c_str(), cost);
    }
  }
  std::cout<<"铺设电路的总长度为: "<<sum<<std::endl;
}
