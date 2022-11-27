#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x][y] = true;
}

// Function to perform BFS on the graph
void bfs(int start)
{
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	// Set source as visited
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		// Print the current node
		cout << vis << " ";
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

int main()
{
// number of vertices
int v = 20;


// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

  addEdge(0, 1);
  addEdge(0, 11);
  addEdge(0, 12);
  addEdge(1, 2);
  addEdge(2, 3);
  addEdge(3, 4);
  addEdge(3, 16);
  addEdge(4, 5);
  addEdge(5, 6);
  addEdge(6, 7);
  addEdge(7, 8);
  addEdge(7, 19);
  addEdge(8, 9);
  addEdge(9, 10);
  addEdge(11, 12);
  addEdge(12, 13);
  addEdge(13, 14);
  addEdge(16, 15);
  addEdge(16, 17);
  addEdge(17, 18);
    

// perform bfs on the graph
bfs(0);
}
