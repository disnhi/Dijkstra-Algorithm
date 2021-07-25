
#include <iostream>
#include <vector>
#include "Graph.h"
//#include <string>

using namespace std;

//automatic empty graph, not constructor or anything

Graph::~Graph() {
  //deconstructor
  for(size_t i = 0; i<this->nodes.size(); i++) {
    delete this->nodes.at(i);
  }
  for(size_t j = 0; j<this->edges.size(); j++) {
    delete this->edges.at(j);
  }
}

GraphNode *Graph::AddNode(char key, int data) {
  //returning a pointer to the new node
  GraphNode *newNode = new GraphNode;
  newNode->key = key;
  newNode->data = data;
  
  int tracker = 0;
  for(size_t i = 0; i<this->nodes.size(); i++) { //To see if there are any other nodes in the list with the same key
    if(this->nodes.at(i)->key == key) {
      tracker = tracker + 1;
    }
  }
  
  if(tracker == 0) { //if there are no duplicate key, then the new node will be added to the list
    nodes.push_back(newNode);
    v = v + 1; //size tracker
    return newNode;
  }
  else {
    cout<<"Node is already in the list."<<endl;
    exit(1);
  } 

}

GraphEdge *Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight) {
  //returns a pointer to the newly created edge
  GraphEdge *newEdge = new GraphEdge;
  newEdge->from = gn1;
  newEdge->to = gn2;
  newEdge->weight = weight;
  

  int tracker = 0;
  for(size_t i = 0; i<this->edges.size(); i++) { //To see if there are any other duplicate edges in the list with the same key
    if((this->edges.at(i)->from == gn1) && (this->edges.at(i)->to == gn2) && (this->edges.at(i)->weight == weight)) {
      tracker = tracker + 1;
    }
  }
  
  if(tracker == 0) { //if there are no duplicate key, then the new node will be added to the list
    edges.push_back(newEdge);
    return newEdge;
  }
  else {
    cout<<"This is a duplicate edge. No new changes made."<<endl;
    exit(1);
  } 

}

string Graph::NodesToString() const { //WORKS!!!

  string nodeString;

  string fullString = "[";
  
  //loops through the nodes vector that contains all the GraphNodes and creates a string of the node key along with its weight
  for(size_t i = 0; i<(this->nodes).size(); i++) {
    nodeString = "(";
    nodeString = nodeString + this->nodes.at(i)->key; //gets the key
    nodeString = nodeString + ":";
    nodeString = nodeString + to_string(this->nodes.at(i)->data); //gets weight

    if(i != (this->nodes).size()-1) { 
      nodeString = nodeString + "), ";
    }
    else {
      nodeString = nodeString + ")]"; 
    }
    fullString = fullString + nodeString;
    nodeString.clear();
  }
  
  return fullString;

}

string Graph::ToString() const {

  //Need to make it return a string that looks like an adjaceny list?
  string fullString;
  string temp;
  int tracker; //to see if the empty list happened.
  int numEdges = 0; //track if there are any edges in the adj list
  
  //GraphNode *nodeTemp = new GraphNode;

  vector<char> n; //all the key nodes

  //creates a vector of all the key nodes for ease of reference
  for(size_t q = 0; q<Graph::Order(); q++) {
    n.push_back(this->nodes.at(q)->key); 
  }

  //goes through each node key that is in the vector...
  for(size_t v = 0; v<n.size(); v++)
    {
      //if there are no edges, it'll just create the empty adj list
      if(this->edges.size() == 0) {
	fullString += n.at(v);
	fullString += " | \n";
      }
      
      else { //if there are edges present, it'll first set up the node. Then it'll iterate through the edges vector to see where the 'from' key is the same as the node. If it comes across one that is the same, it'll add the appropriate values, characters, and notation to the string.

	fullString += n.at(v); //sets up the first node in the string
	fullString += " | ";

	for(size_t k = 0; k<(this->edges).size(); k++)
	  {

	    if(n.at(v) == this->edges.at(k)->from->key)
	      { //searches the edge vector for match node keys.
		numEdges += 1; //adds one to tracker
		char from = (this->edges).at(k)->from->key;
		string fromData = to_string((this->edges).at(k)->from->data);
	
		char to = (this->edges).at(k)->to->key;
		string toData = to_string((this->edges).at(k)->to->data);
	
		string w = to_string((this->edges).at(k)->weight); //weight
	
		fullString += "[(";
		fullString += from;
		fullString += ":";
		fullString += fromData;
		fullString += ")->(";
		fullString += to;
		fullString += ":";
		fullString += toData;
		fullString += ") w:";
		fullString += w;
		fullString += "], ";

		tracker += 1; //just for my reference to know when there's something in the edges
		
	      }
	    
	    if( (k ==(this->edges.size()-1)) && (tracker!= 0) )
	      { //if it's the last k value and there's something in that node's edge list, it means it's the last edge in that list so it'll erase the comma and space after the last group.
		fullString.erase(fullString.begin() + (fullString.size() - 2));
	      
		if(tracker!=0)
		  { //if the tracker isn't 0, it means there's an edge in the adj list so there's an extra space still present. this gets rid of it for the assert to be correct.
		    fullString.erase(fullString.begin()+fullString.size()-1);
		  }
	      }
	  }
	fullString = fullString + "\n";
	tracker = 0; //resetting tracker for next iteration of nodes.
      }
    }

  return fullString;
  
}	  	     

string Graph::GraphNodeToString(const GraphNode *gn) {
  
  string node = "(";

  node += gn->key;
  node += ":";
  node += to_string(gn->data);
  node += ")";

  return node; 
  
}

string Graph::GraphEdgeToString(const GraphEdge *ge) {

  string edge = "(";

  //adds the from node to the string
  edge += ge->from->key;
  edge += ":";
  edge += to_string(ge->from->data);
  edge += ")->(";

  //adds the to node from the string
  edge += ge->to->key;
  edge += ":";
  edge += to_string(ge->to->data);
  edge += ") w:";
  edge += to_string(ge->weight); //adds weight

  return edge;
  
}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const { 

  return edges;

}

const vector<GraphNode*>& Graph::GetNodes() const { 
  
  return this->nodes;
}

const GraphNode* Graph::NodeAt(unsigned int idx) const {

  GraphNode *temp;

  //uses the class' private member "nodes" to find the node at the given index
  temp = this->nodes.at(idx);
  return temp;

}

size_t Graph::Size() const {

  size_t temp = this->edges.size();
  return temp;

}

size_t Graph::Order() const {

  size_t temp = this->nodes.size();
  return temp;
  
}


			  
