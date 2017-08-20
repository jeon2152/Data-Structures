#include <iostream>			// header
#include <queue>			// header
#include <stack>			// header
#include "BitMatrixGraph.h"

using namespace std;

/*void printBits(unsigned char s) {
	//print the bit pattern
	for (int i = 0; i < 8; i++)
		if (s & (1 << (7 - i)))
			cout << 1;
		else
			cout << 0;
}*/

/*int main() {
	int n = 10;
	int size;
	// Create the bit Adjacency Matrix structure
	if (n % 8 == 0)
		size = n / 8;
	else
		size = (int)(n / 8) + 1;
	unsigned char** bitAdjacencyMatrix;
	bitAdjacencyMatrix = new unsigned char*[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}
	//Initialize the bit Adjacency Matrix structure
	for (int i = 0; i < n; i++){
		for (int j = 0; j < size; j++)
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
	}
	//Print the bit Adjacency Matrix structure
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++)
			printBits(bitAdjacencyMatrix[i][j]);
		cout << i << endl;
	}
}*/

/*int main() {
	unsigned char l = 0x01 << 1; // set l to be equal to 2;
	cout << "Printing the bits before changing: ";
	printBits(l);
	cout << endl;
	//set the third bit from right to be a 1
	l |= 0x01 << 2;
	cout << "Printing the bits after setting the third bit from the right to be a 1: ";
	printBits(l);
	cout << endl;
	//set the second bit from the right to be a 0
	l &= ~(0x01 << 1);
	cout << "Printing the bits after setting the second bit from the right to be a 0: ";
	printBits(l);
	cout << endl;
	//check the second bit from the right
	if (l & (1 << 1))
		cout << "Second bit from right is set" << endl;
	else
		cout << "Second bit from right is not set" << endl;
}*/

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


