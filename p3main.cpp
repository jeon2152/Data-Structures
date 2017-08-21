#include <iostream>			// header
#include <queue>			// header
#include <stack>			// header
#include "BitMatrixGraph.h"

using namespace std;

int main() {
	int node;
	int vertexU, vertexV;
	
	// Read the number of nodes from input file
	cin >> node;
	//cout << node << endl;
	
	// Construct the bitAdjacencyMatrix 
	BitMatrixGraph *myGraph = new BitMatrixGraph(node);
	
	// Read the edges between vertex U and V from input file and assign them to the matrix
	while (!cin.eof()) {
		cin >> vertexU >> vertexV;
		//cout << vertexU << " " << vertexV << endl;
		myGraph -> addEdge(vertexU, vertexV);
	}
	//cout << endl;

	// Print out the bitAdjacencyMatrix
	cout << "=======================================================" << endl;
	cout << "                   BitAdjacencyMatrix" << endl;
	cout << "=======================================================" << endl;

	cout << *myGraph << endl;
	
	// Perform Breadth First Search
	cout << "=======================================================" << endl;
	cout << "                          BFS" << endl;
	cout << "=======================================================" << endl;
	cout << "BFS starting from the Node 0:\n" << endl;
	
	myGraph->bfs(0);
	cout << endl;
	
	// Perform Depth First Search
	cout << "=======================================================" << endl;
	cout << "                          DFS" << endl;
	cout << "=======================================================" << endl;
	cout << "DFS starting from the Node 0:\n" << endl;

	myGraph->dfs(0);
	cout << endl;

	// Employ destructor
	cout << "=======================================================" << endl;
	cout << "                      DESTRUCTOR" << endl;
	cout << "=======================================================" << endl;

	delete myGraph;
	cout << *myGraph << endl;	// check if destructor works

}


