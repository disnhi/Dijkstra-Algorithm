OPTS = -Wall

all: graph-tests bpq-tests dijkstra

graph-tests: GraphTests.cpp Graph.cpp
	g++ -std=c++11 ${OPTS} -o graph-tests GraphTests.cpp Graph.cpp

bpq-tests: BPQTests.cpp BetterPriorityQueue.cpp Graph.cpp
	g++ -std=c++11 ${OPTS} -o bpq-tests BPQTests.cpp BetterPriorityQueue.cpp Graph.cpp

dijkstra: Dijkstra.cpp BetterPriorityQueue.cpp Graph.cpp
	g++ -std=c++11 ${OPTS} -o dijkstra Dijkstra.cpp BetterPriorityQueue.cpp Graph.cpp
