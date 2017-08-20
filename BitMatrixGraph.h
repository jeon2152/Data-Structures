#pragma once
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BitMatrixGraph {

	friend ostream& operator<< (ostream&, BitMatrixGraph&);	// ostream operator

protected:
	unsigned char** bitAdjacencyMatrix;		// bitwise adjacency matrix
	int n;							// number of nodes in the graph
	int size;						// number of unsigned characters per row

public:
	BitMatrixGraph();				// empty constructor
	BitMatrixGraph(int numNodes);	// non-empty constructor
	BitMatrixGraph(const BitMatrixGraph& otherGraph);	// copy constructor
	~BitMatrixGraph();				// destructor of BitMatrixGraph class

	BitMatrixGraph operator= (const BitMatrixGraph& b);	// overloaded = operator
	
	int positionChar(int ch);		// positionChar method - point out the position in column using character size (8bits)
	int positionBit(int bt);		// positionBit method - point out the position in row and char-column using bit
	void addEdge(int u, int v);		// addEdge method - add 1 into the bit matrix if there is an edge
	bool isAnEdge(int u, int v);	// isAnEdge method - check if there is an edge between the vertices u and v

	void bfs(int u);				// bfs method - perform the breadth first search and show the parent nodes
	void dfs(int u);				// dfs method - perform the depth first search and show the parent nodes
	void dfsRecursive(int u, bool* visited, int* parent, int parentNum);		// dfsRecursive method - do recursion in the depth first search

};

// Call printBits method (defined later but to be used for ostream operator<<)
void printBits(unsigned char s);

// ostream operator<<
ostream& operator<< (ostream& os, BitMatrixGraph& graph) {
	
	for (int i = 0; i < graph.n; i++) {
		for (int j = 0; j < graph.size; j++) {
			printBits(graph.bitAdjacencyMatrix[i][j]);
		}
		cout << endl;
	}
	return os;
}

// overloaded operator=
BitMatrixGraph BitMatrixGraph::operator= (const BitMatrixGraph& b){
	return b;
}

// BitMatrixGraph empty constructor
BitMatrixGraph::BitMatrixGraph() {}

// BitMatrixGraph non-empty constructor
BitMatrixGraph::BitMatrixGraph(int numNodes) {

	//int size;		// In case of local variable
	
	//Create bitAdjacencyMatrix structure
	this->n = numNodes;
	
	if (n % 8 == 0) 
		size = n / 8;
	else 
		size = (int)(n / 8) + 1;

	bitAdjacencyMatrix = new unsigned char*[n];
	
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
		for (int j = 0; j < size; j++)
			bitAdjacencyMatrix[i][j] = 0x00 << 8;	// Initialize the bitAdjacencyMatrix structure with 0
	}
}

// BitMatrixGraph copy constructor
BitMatrixGraph::BitMatrixGraph(const BitMatrixGraph& otherGraph) {
	
	n = otherGraph.n;
	bitAdjacencyMatrix = otherGraph.bitAdjacencyMatrix;
}

// BitMatrixGraph destructor
BitMatrixGraph::~BitMatrixGraph() {

	for (int i = 0; i < n; i++) {
		delete[] bitAdjacencyMatrix[i];
		
	}
	delete[] bitAdjacencyMatrix;
	cout << "Destroy the constructor." << endl;
}

// BitMatrixGraph methods
int BitMatrixGraph::positionChar(int ch) {

	int pos;
	if (ch == 0) pos = 0;
	else if (ch % 8 == 0) 
		pos = (ch / 8) - 1;
	else
		pos = (int)(ch / 8);

	return pos;
}

int BitMatrixGraph::positionBit(int bt) {

	int k;
	k = 7 - (bt % 8);

	return k;
}

void BitMatrixGraph::addEdge(int u, int v) {

	if (u >= 0 && u < n && v >= 0 && v < n) {
		// Check if edge already exists
		if (isAnEdge(u, v)) {
			// Edge already exists
			cout << "Error, egde between " << u << " and" << v << " already exists." << endl;
		}
		else {
			// Add edge from u to v
			bitAdjacencyMatrix[u][positionChar(v)] |= 0x01 << positionBit(v);
			bitAdjacencyMatrix[v][positionChar(u)] |= 0x01 << positionBit(u);
			//cout << "Adding edge between " << u << " and" << v << " is completed." << endl;
		}
	}
}

bool BitMatrixGraph::isAnEdge(int u, int v) {

	if (u >= 0 && u < n && v >= 0 && v < n) {
		if ((bitAdjacencyMatrix[u][positionChar(v)] & (1 << positionBit(v))) && 
			(bitAdjacencyMatrix[v][positionChar(u)] & (1 << positionBit(u))))
			return true;
		else
			return false;
	}
}

void BitMatrixGraph::bfs(int u) {

	int* parent = new int[n];
	bool* visited = new bool[n];
	int* bfsNums = new int[n];
	int bfsNum;
	queue<int> Q;

	parent[u] = -1;		// Assign the parent of first (starting) node to be -1

	// Fill the visited array with false
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	// Fill the bfsNums array with 0
	for (int i = 0; i < n; i++) {
		bfsNums[i] = 0;
	}

	bfsNum = 0;
	Q.push(u);
	visited[u] = true;

	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		bfsNum++;
		bfsNums[v] = bfsNum;

		for (int w = 0; w < n; w++) {
			if (isAnEdge(v, w) == true && visited[w] == false) {
				parent[w] = v;
				Q.push(w);
				visited[w] = true;
			}
		}
	}

	//cout << endl;
	for (int i = 0; i < n; i++) {
		if (i < 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
	}
	cout << " <- Node" << endl;

	for (int i = 0; i < n; i++) {
		if (parent[i] > -1 && parent[i] < 10)
			cout << " " << parent[i] << " ";
		else
			cout << parent[i] << " ";
	}
	cout << " <- Parent node" << endl;

	delete[] parent;
	delete[] visited;
	delete[] bfsNums;
}

void BitMatrixGraph::dfs(int u) {

	int* parent = new int[n];
	bool* visited = new bool[n];
	int parentNum;

	// Fill the visited array with false
	for (int i = 0; i < n;i++) {
		visited[i] = false;
	}

	parentNum = -1;		// Assign the parent of first (starting) node to be -1
	dfsRecursive(u, visited, parent, parentNum);

	for (int i = 0; i < n; i++) {
		if (i < 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
	}
	cout << " <- Node" << endl;

	for (int i = 0; i < n; i++) {
		if (parent[i] > -1 && parent[i] < 10)
			cout << " " << parent[i] << " ";
		else
			cout << parent[i] << " ";
	}
	cout << " <- Parent node" << endl;

	delete[] parent;
	delete[] visited;

}

void BitMatrixGraph::dfsRecursive(int u, bool* visited, int* parent, int parentNum) {
	
	visited[u] = true;
	parent[u] = parentNum;

	for (int v = 0; v < n;v++) {
		if (isAnEdge(u, v) == true && visited[v] == false) {
			dfsRecursive(v, visited, parent, u);
		}
	}
}

// (global) printBits method (used in ostream operator<<)
void printBits(unsigned char s) {
	for (int i = 0; i < 8; i++) {
		if (s & (1 << (7 - i)))
			cout << 1;
		else
			cout << 0;
	}
}
