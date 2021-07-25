
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;


//Big O Time Complexity for this function would be O(n) * O(nlog(n)) which would just simplify to O(nlog(n)) because constants don't matter for big O time complexity. The O(n) came from the first for loop and the O(nlog(n)) came from the nest for loop within the while loop.
int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){

  int total = 0; //Final answer

  if(g->Size() == 0) {
    cout<<"Sorry, that graph was empty."<<endl;
    exit(1);
  }

  if(start == end) { //if the starting node is also the ending node.
    return total;
  }

  BetterPriorityQueue queue; //main queue

  vector<GraphNode*> listNodes = g->GetNodes(); 

  for(size_t i = 0; i < listNodes.size(); i++) { //adding all the nodes into the queue
    DNode cur;
    //dont need to do the cur.pri bc it's already set to int_max.
    cur.node = listNodes.at(i);;
    queue.push(cur);
  }

  DNode temp; //starting node
  temp.pri = 0;
  temp.visited = true;
  temp.node = start;

  queue.Update(temp); //updates the starting node's priority to 0 to begin the algorithm

  cout<<BetterPriorityQueue::DnodeToString(queue.top())<<endl; 

  vector<GraphEdge*>listEdges = g->GetEdges(start); //retrieves ALL the edges in the graph

  while(temp.node != end) { //iterates thrpugh until the end node is met or until there is nothing left in queue
    
    for(size_t i = 0; i<listEdges.size(); i++) {
      
      if(listEdges.at(i)->from->key == temp.node->key) //if the from node matches the current "temp" node
	{
	  DNode toNode; //The node that the edge is going to (for update)
	  toNode.pri = listEdges.at(i)->weight;
	  toNode.node = listEdges.at(i)->to;
	  
	  int curPri = queue.Get(listEdges.at(i)->to->key); //finds the current priority value of the node in which the edge is going to.

	  int placeHolder = temp.pri + toNode.pri; //what the next node's pri value would be
	  if(curPri>placeHolder) {
	    DNode reset; //resets the value to account for the pri values that are still INT_MAX
	    reset.pri = 0;
	    reset.node = listEdges.at(i)->to;
	    queue.Update(reset);

	    toNode.pri = placeHolder; //sets pri to new value
	    queue.Update(toNode); 
	    
	  }
	} 
    }
    queue.pop(); //takes out the node that was just evaluated
    temp = queue.top(); //evaluates the next node in the queue with the smallest pri number
    
    cout<<BetterPriorityQueue::DnodeToString(queue.top())<<endl;
  }

  total = temp.pri;

  if(total == INT_MAX) { //to account for when the end node is not connected to any node
    cout<<"No possible path to the end node."<<endl;
    exit(1);
  }
  else {
    return total;
  }
}


int DijkstraTest(){
	
  Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	cout << g->ToString() << endl;
	
	unsigned int ans = dijkstra(g->NodeAt(0), e, g);
	assert(ans == 20);

	delete g;
		
	return ans;
}

int DijkstraTest2(){

  Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 4);
	g->AddEdge(b, c, 6);
	g->AddEdge(c, f, 7);
	g->AddEdge(a, d, 8);
	g->AddEdge(b, d, 7);
	g->AddEdge(d, e, 3);
	
	g->AddEdge(e, c, 5);
	g->AddEdge(e, f, 8);	
	
	cout << g->ToString() << endl;
	
	unsigned int ans = dijkstra(g->NodeAt(0), f, g);
	assert(ans == 17);

	delete g;
		
	return ans;

}

int DijkstraTest3() {
  //empty graph test;

  Graph *g = new Graph();
  
  GraphNode *a = g->AddNode('1');
  GraphNode *b = g->AddNode('2');

  cout << g->ToString() << endl;

  int ans = dijkstra(a,b,g);

  delete g;

  return ans;
}

int DijkstraTest4() {
  //unreachable node test.
  
  Graph *g = new Graph();
  
  GraphNode *a = g->AddNode('1');
  GraphNode *b = g->AddNode('2');
  GraphNode *c = g->AddNode('3');

  g->AddEdge(a,b,3);
  
  cout << g->ToString() << endl;

  int ans = dijkstra(g->NodeAt(0),c,g);

  delete g;

  return ans;
  
}


int main(){
	
  int ans = DijkstraTest();
  cout << "ans: "  << ans << endl<<endl;
	
  /*	
  int ans2 = DijkstraTest2();
  cout << "ans: " << ans2<< endl<<endl;

  int ans3 = DijkstraTest3();
  cout << "ans: "<<ans3<<endl<<endl;

  int ans4 = DijkstraTest4();
  cout << "ans: "<<ans4<<endl<<endl;
  */	
	
	
  return 0;
}
