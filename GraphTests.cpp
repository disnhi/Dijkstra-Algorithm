//Homework 5

#include "Graph.h"
#include <iostream>
#include <cassert>

using namespace std;


void TestAddNode(){
	cout << "Testing AddNode..." << endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl; 
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	// more tests....

	
	cout << "PASSED!" << endl << endl;
}


void TestAddEdge(){
	cout << "Testing AddEdge..." << endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	GraphNode *gn2 = g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	GraphNode *gn3 = g.AddNode('c', 9);
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | \nb | \nc | \n");
	
	g.AddEdge(gn1, gn3, 2);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	//cout << g.ToString() << endl;
	//cout << "a | [(a:15)->(c:9) w:2]  \nb |  \nc |  \n" << endl;

	
	g.AddEdge(gn3, gn2);
	g.AddEdge(gn1, gn2, 8);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n");

	//Testing duplicate edge. It works by exiting the program.
	//g.AddEdge(gn1, gn2, 8);
	//cout<<"graph: "<<endl<<g.ToString()<<endl;
	
	cout << "PASSED!" << endl << endl;
}


void TestDestructor(){
	cout << "Testing Destructor..." << endl;
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('a', 3);
	GraphNode *b = g->AddNode('b', 5);
	g->AddEdge(b, a, 15);
	
	delete g;
	
	
	Graph g2 = Graph();
	GraphNode *c = g2.AddNode('c', 12);
	g2.AddNode('d', 11);
	assert(c->key == 'c' && c->data == 12);
	
	
	
	cout << "NO ERRORS.  Use valgrind to check!" << endl << endl;
}


// more test functions...*/

void TestGraphNodeToString() {
  cout<<"Testing GraphNodeToString..."<<endl;

  Graph *g = new Graph();

  GraphNode *gn1 = g->AddNode('a', 1);
  assert(Graph::GraphNodeToString(gn1) == "(a:1)");
  
  GraphNode *gn2 = g->AddNode('b', 2);
  assert(Graph::GraphNodeToString(gn2) == "(b:2)");


  delete g;
  
  cout<<"PASSED!"<<endl<<endl;
  
}

void TestGraphEdgeToString() {
  cout<<"Testing GraphEdgeToString..."<<endl;

  Graph *g = new Graph();

  GraphNode *gn1 = g->AddNode('a',1);
  GraphNode *gn2 = g->AddNode('b',2);

  GraphEdge *ge = g->AddEdge(gn1,gn2,5);
  assert(Graph::GraphEdgeToString(ge) == "(a:1)->(b:2) w:5");

  //cout<<"EDGE: "<<Graph::GraphEdgeToString(ge)<<endl;

  delete g;

  cout<<"PASSED!"<<endl<<endl;
  
}

void TestGetEdges() {
  cout<<"Testing GetEdges..."<<endl;

  Graph g = Graph();
  
  GraphNode *gn1 = g.AddNode('a', 15);
  GraphNode *gn2 = g.AddNode('b', 12);
  GraphNode *gn3 = g.AddNode('c', 9);
  
  g.AddEdge(gn1, gn3, 2);
  g.AddEdge(gn3, gn2);
  g.AddEdge(gn1, gn2, 8);

  g.GetEdges(gn1);


  cout<<"PASSED!"<<endl<<endl;
  
}

void TestGetNodes() {
  cout<<"Testing GetNode..."<<endl;

  Graph g = Graph();
  
  g.AddNode('a', 15);
  g.AddNode('b', 12);
  g.AddNode('c', 9);
  

  cout<<"PASSED!"<<endl<<endl;
 
}

void TestNodeAt() {
  cout<<"Testing NodeAt..."<<endl;
  
  Graph g = Graph();
  g.AddNode('a',15);
  g.AddNode('b',17);
  g.AddNode('c',14);

  assert(Graph::GraphNodeToString(g.NodeAt(0)) == "(a:15)");
  assert(Graph::GraphNodeToString(g.NodeAt(1)) == "(b:17)");
  assert(Graph::GraphNodeToString(g.NodeAt(2)) == "(c:14)");
  

  //cout<<Graph::GraphNodeToString(g.NodeAt(1))<<endl;

  cout<<"PASSED"<<endl<<endl;
 
}


int main(){
	
  TestAddNode();
  TestNodeAt();
  TestAddEdge();
  TestDestructor();
  
  TestGraphNodeToString();
  TestGraphEdgeToString();
  TestGetEdges();
  TestGetNodes();
	
  cout << "ALL TESTS PASSED!" << endl;
  //return 0;
}
