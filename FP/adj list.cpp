#include <bits/stdc++.h>
using namespace std;

// Function to add edges
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Function to print adjacency list
void adjacencylist(vector<int> adj[], int V)
{
	for (int i = 0; i < V; i++) {
		cout << i << "->";
		for (int& x : adj[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

// Function to initialize the adjacency list
// of the given graph
void initGraph(int V, int edges[20][19], int noOfEdges)
{
	// To represent graph as adjacency list
	vector<int> adj[V];

	// Traverse edges array and make edges
	for (int i = 0; i < noOfEdges; i++) {

		// Function call to make an edge
		addEdge(adj, edges[i][0], edges[i][1]);
	}

	// Function Call to print adjacency list
	adjacencylist(adj, V);
}

// Driver Code
int main()
{
	// Given vertices
	int V = 20;

	// Given edges
	int edges[20][19] = { 
	{ 0, 1 }, 
	{ 0, 11 }, 
	{ 0, 12 }, 
	{ 1, 2 }, 
	{ 2, 3 }, 
	{ 3, 4 }, 
	{ 3, 16 },
	{ 4, 5 }, 
	{ 5, 6 }, 
	{ 6, 7 },
	{ 7, 8 }, 
	{ 7, 19 }, 
	{ 8, 9 }, 
	{ 9, 10 }, 
	{ 11, 12 }, 
	{ 12, 13 }, 
	{ 13, 14 }, 
	{ 16, 15 }, 
	{ 16, 17 }, 
	{ 17, 18 } 
	};

	int noOfEdges = 20;

	// Function Call
	initGraph(V, edges, noOfEdges);

	return 0;
}
