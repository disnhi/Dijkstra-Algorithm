# Dijkstra-Algorithm

This program implements Dijkstra's algorithm for finding the shortest path between nodes in a graph. To implement Dijkstra's algorithm, we need an Update() method to change the priority of items in the queue. We'll do this by extending the standard library priority queue with a child-class. The BetterPriorityQueue contains four new public methods: 'Contains()', 'Update()', 'ToString()', and 'DnodeToString()'

Contains(): Takes a DNode and returns true if that DNode is in the queue.

Update(): Takes a DNode and uses the values in that DNode to change the priority of a matching DNode.

ToString(): Returns a string representation of the queue.

DnodeToString(): Takes a DNode struct and returns a string representation 