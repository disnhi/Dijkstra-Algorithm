
#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include "Graph.h"
#include <string>
#include <iostream>
#include <queue>
#include <bits/stdc++.h> //required for Linux system but not for mac os

using namespace std;

struct DNode {
  int pri = INT_MAX;
  bool visited = false;
  const GraphNode *node = nullptr;
	
  bool operator<(const DNode &other) const {
    return pri < other.pri;
  }

  bool operator>(const DNode &other) const {
    return pri > other.pri;
  }
	
  bool operator==(const DNode &other) const {
					     return node == other.node;
  }
};

class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue {

  public:

  int Get(char key);
  bool Contains(const DNode &temp) const;
  bool Update(const DNode &temp);
  string ToString() const;
  static string DnodeToString(const DNode &temp);
  
};

#endif
