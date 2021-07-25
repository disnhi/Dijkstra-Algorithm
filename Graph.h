#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector> //for matrix

using namespace std;

struct GraphNode {
  char key;
  int data; // Not necessary or used for Dijkstra algorithm
};


struct GraphEdge {
  GraphNode *from;
  GraphNode *to;	
  unsigned int weight;
};


class Graph {
	
public:
  ~Graph();
	
  GraphNode *AddNode(char key, int data = 0);
  GraphEdge *AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0);
		
  string NodesToString() const;
  string ToString() const;

  static string GraphNodeToString(const GraphNode *gn);
  static string GraphEdgeToString(const GraphEdge *ge);
		
		
  const vector<GraphEdge*>& GetEdges(const GraphNode *gn) const;
  const vector<GraphNode*>& GetNodes() const;
  const GraphNode* NodeAt(unsigned int idx) const;
  size_t Size() const; // the number of edges
  size_t Order() const; // the number of nodes

private:

  int v; //number of vertices. keeps track of nodes.
  vector<GraphNode*> nodes;
  vector<GraphEdge*> edges;
  vector<vector<GraphEdge*>> adj;

  //maybe make a vector of GraphEdges as well.
  //gotta make it the vector pointers so vector<GraphNode> *nodes;
  

};
  
#endif
