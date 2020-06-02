#include <iostream>
#include "MyGraph.h"

void printMenu() {
  std::cout<<"===== 景区信息管理系统 ====="<<std::endl;
  std::cout<<"1.创建景区景点图\n";
  std::cout<<"2.查询景点信息\n";
  std::cout<<"3.旅游景点导航\n";
  std::cout<<"4.搜索最短路径\n";
  std::cout<<"5.铺设电路规划\n";
  std::cout<<"0.退出\n";
}
int main() {

  MyGraph g;
  int command=1;
  while (command != 0) {
    printMenu();
    std::cin>>command;
    switch(command) {
      case 1:
        g.init("Vex.txt", "Edge.txt");
        break;
      case 2:
        std::cout<<"===== 查询景点信息 =====\n";
        g.printVexs();
        std::cout<<"请输入想要查询的景点信息: ";
        int vexi;
        std::cin>>vexi;
        g.printVex(vexi);
        break;
      case 3:
        std::cout<<"===== 旅游景点导航 =====\n";
        g.printVexs();
        int vexi2;
        std::cout<<"请输入起始点编号: ";
        std::cin>>vexi2;
        g.dfsTravel(vexi2);
        break;
      case 4:
        std::cout<<"===== 搜索最短路径 =====\n";
        g.printVexs();
        int fromi, toi;
        std::cout<<"请输入起点的编号: ";
        std::cin>>fromi;
        std::cout<<"请输入终点的编号: ";
        std::cin>>toi;
        g.finMinPath(fromi, toi);
        break;
      case 5:
        std::cout<<"===== 铺设电路规划 =====\n";
        std::cout<<"在以下两个景点之间铺设电路:\n";
        g.prime();
        break;
      default:
        std::cout<<"暂不支持此操作\n";
    }
  }

  return 0;
}
