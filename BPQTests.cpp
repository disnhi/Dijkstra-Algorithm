
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <cassert>

using namespace std;

void ContainsTest() {
	cout << "Testing Contains Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	GraphNode *a = g.AddNode('a');
	DNode n;
	n.node = a;
	q.push(n);

	assert(q.Contains(n) == true);
	

	// more tests go here!
	
	
	cout << "PASSED!" << endl << endl;
}

void UpdateTest() {
	cout << "Testing Update Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode('a');
	g.AddNode('b');
	g.AddNode('c');
	g.AddNode('d');
	GraphNode *e = g.AddNode('e');
	GraphNode *f = g.AddNode('f');
	vector<GraphNode*> nodes = g.GetNodes();
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		cur.pri = i;
		cur.node = nodes.at(i);
		//cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q.push(cur);
		//cout << "size: " << q.size() << endl;
	}
	

	//cout << "q before: " << q.ToString() << endl;

	DNode positive;
	positive.node = f;
	positive.pri = 0;
	//cout << "q before: " << q.ToString() << endl;
	assert(q.Update(positive) == true);
	//cout << "q after: " << q.ToString() << endl;


	// Either one of these solutions is correct depending on
	// how you implement the priority queue
	string soln1 = "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 4), (c: 2)]";
	string soln2 = "[(f: 0), (b: 1), (a: 0), (d: 3), (e: 4), (c: 2)]";
	assert(q.ToString() == soln1 || q.ToString() == soln2);
	
	
	// more tests go here...
	DNode test;
	test.node = e;
	test.pri = 1;
	assert(q.Update(test) == true);

	string testSol = "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 1), (c: 2)]";
	assert(q.ToString() == testSol);
	
	cout << "PASSED!" << endl<<endl;
	}


void TestDnodeToString() {
  cout<<"Testing DnodeToString..."<<endl;

  Graph g = Graph();
  GraphNode *a = g.AddNode('a');
  DNode temp;
  temp.node = a;
  temp.pri = 1;
  assert(BetterPriorityQueue::DnodeToString(temp) == "(a:1)");

  
  cout<<"PASSED!"<<endl<<endl;

}

int main(){
	
  ContainsTest();
  UpdateTest();
  TestDnodeToString();
	
	cout << "ALL TESTS PASSED!!" << endl;
	
	return 0;
	
}
