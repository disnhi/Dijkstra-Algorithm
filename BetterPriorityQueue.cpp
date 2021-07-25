#include <iostream>
#include "BetterPriorityQueue.h"

#include <string>
#include <vector>

using namespace std;

int BetterPriorityQueue::Get(char key) {
  //A helper method to get the weight of the key in the queue.
  int temp = 0;
  for(size_t i = 0; i<c.size(); i++) {
    if(c.at(i).node->key == key){
      temp = c.at(i).pri;
    }
  }
  return temp;
}

bool BetterPriorityQueue::Contains(const DNode &temp) const {
  //checks to see if the DNode is in the priority_queue and returns true if it is
  //we get a variable c, which is the vector of the DNode, which is the queue. so to see if temp is in queue, loop through c.

  for(size_t i = 0; i<c.size(); i++) {
    if(c.at(i) == temp) {
      return true;
    }
  }
  
  return false; //This method will resort to returning false if it isn't able to find the node in the priority queue from the loop above

}

bool BetterPriorityQueue::Update(const DNode &temp) {
  
  int tracker = 0; //sees if it does the update
 

  vector<DNode> tempQueue; //creates a temporary vector of Dnodes to hold the current DNodes in the priority queue.

  for(size_t i = 0; i<c.size(); i++) { //loops through all values in implicit queue.
    DNode cur;
    
    if(c.at(i).node->key == temp.node->key) { 
      cur = temp; //assigns the new priority value to the proper key
      tracker += 1; //track that the key is in the priority queue
    }
    else { //copies the rest of the key and its priority value
      cur.pri = c.at(i).pri;
      cur.node = c.at(i).node;
    }
    tempQueue.push_back(cur); 
  }

  while(!c.empty()) { //clears the current priority queue
    c.pop_back();
  }

  for(size_t j = 0; j<tempQueue.size(); j++) { //re-insert the Dnodes, along with the new priority value into the implicit priority queue.
    this->push(tempQueue.at(j)); //performs the bubble up heap queue
  }
 
  if(tracker != 0) { //returns true if the priority value was updated.
    return true;
  }
  else {
    return false;
  }
  
}

string BetterPriorityQueue::ToString() const { 
  //Takes the implicit parameter and converts the node and its cooresponding weight to a string.
  string pqString = "[";
  for(size_t i = 0; i<c.size(); i++) {
    pqString = pqString + '(' + c.at(i).node->key;
    pqString = pqString + ": " + to_string(c.at(i).pri) + ")";

    if(i != c.size()-1) //if it's the last item in the queue, it adds the comma and space
      {
	pqString += ", ";
      }
  }
  pqString = pqString + ']';
  return pqString;

}

string BetterPriorityQueue::DnodeToString(const DNode &temp) {
  //Takes the DNode temp and iterates through to convert the node and its corresponding priority in the queue into a string.

  string nodeString = "(";
 
  nodeString += temp.node->key; //adds key
  nodeString += ':';
  nodeString += to_string(temp.pri) + ")"; //adds priority
    
  return nodeString;
  
}
