#include <bits/stdc++.h>
using namespace std;

class graph {
    
    private:
        int v;
        vector<int> *adj;

    public:
        graph(int v) {
            this->v = v;
            adj = new vector<int> [v];
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
        }

        void print_path(int source, int dest);
        bool BFS(int source, int dest, int parent[]);
};

void graph::print_path(int source, int dest) {

    // it stores parent for each vertex to trace the path.
    int parent[v];

    if(BFS(source, dest, parent) == false) {
        cout << "Destination is not reachable from this source.\n";
        return;
    }

    stack<int> st;

    while(parent[dest] != -1) {
        st.push(dest);
        dest = parent[dest];
    }

    cout << source;
    while(!st.empty()) {
        cout << " -> " << st.top();
        st.pop();
    }

    return;
}

bool graph::BFS(int source, int dest, int parent[]) {

    queue<int> q;
    bool visited[v];

    for(int i=0; i<v; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    q.push(source);
    visited[source] = true;

    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        for(int k: adj[temp]) {
            if(visited[k] == false) {

                q.push(k);
                visited[k] = true;
                parent[k] = temp;

                if(k == dest)
                    return true;
            }
        }
    }
    return false;
}

int main() {

  graph g(20);

  g.addEdge(0, 1);
  g.addEdge(0, 11);
  g.addEdge(0, 12);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(3, 16);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  g.addEdge(6, 7);
  g.addEdge(7, 8);
  g.addEdge(7, 19);
  g.addEdge(8, 9);
  g.addEdge(9, 10);
  g.addEdge(11, 12);
  g.addEdge(12, 13);
  g.addEdge(13, 14);
  g.addEdge(16, 15);
  g.addEdge(16, 17);
  g.addEdge(17, 18);

  g.print_path(0, 13);

    return 0;
}