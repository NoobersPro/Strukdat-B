#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

// menyimpan informasi tentang sebuah vertex
struct Vertex {
    int id;
    int distance;
};

// menyimpan informasi tentang sebuah edge
struct Edge {
    int u, v, w;
};

// menyimpan informasi tentang sebuah graph
struct Graph {
    int num_vertices;
    vector<Edge> edges;
    vector<vector<pair<int, int>>> adjacency_list;
};

// membuat graph baru dengan jumlah vertex yang diberikan
Graph create_graph(int num_vertices) {
    Graph graph;
    graph.num_vertices = num_vertices;
    graph.adjacency_list.resize(num_vertices);
    return graph;
}

// menambahkan edge dari u ke v dengan bobot w pada graph
void add_edge(Graph& graph, int u, int v, int w) {
    graph.edges.push_back({u, v, w});
    graph.adjacency_list[u].push_back({v, w});
}

// mencari jalur terpendek dari vertex start ke vertex end menggunakan DFS
pair<vector<int>, int> dfs(const Graph& graph, int start, int end) {
    // menyimpan jarak terpendek dari start ke setiap vertex
    vector<int> distance(graph.num_vertices, INF);
    // menyimpan parent dari setiap vertex
    vector<int> previous(graph.num_vertices, -1);
	// memulai dengan start vertex
	distance[start] = 0;
	stack<Vertex> st;
	st.push({start, 0});
	
while (!st.empty()) {
    // mengambil vertex dari top stack
    Vertex u = st.top();
    st.pop();

    // jika u merupakan vertex tujuan, keluar dari loop
    if (u.id == end) break;

    // kunjungi setiap vertex yang terhubung dengan u
    for (pair<int, int> v : graph.adjacency_list[u.id]) {
        // jika v terhubung dengan u dan jaraknya lebih pendek dari sebelumnya, perbarui jarak terpendek dari start ke v
        if (distance[v.first] > distance[u.id] + v.second) {
            distance[v.first] = distance[u.id] + v.second;
            previous[v.first] = u.id;
            st.push({v.first, distance[v.first]});
        }
    }
}

// membuat jalur terpendek dari start ke end
vector<int> path;
int current = end;
while (current != start) {
    path.push_back(current);
    current = previous[current];
}
path.push_back(start);

return {path, distance[end]};
}

int main() {
Graph graph = create_graph(20);
add_edge(graph, 0, 0, 10);
add_edge(graph, 0, 1, 5);
add_edge(graph, 0, 11, 1);
add_edge(graph, 0, 12, 2);
add_edge(graph, 1, 2, 4);
add_edge(graph, 2, 3, 6);
add_edge(graph, 3, 4, 2);
add_edge(graph, 3, 16, 6);
add_edge(graph, 4, 5, 10);
add_edge(graph, 5, 6, 5);
add_edge(graph, 6, 7, 1);
add_edge(graph, 7, 8, 2);
add_edge(graph, 7, 19, 4);
add_edge(graph, 8, 9, 6);
add_edge(graph, 9, 10, 2);
add_edge(graph, 10, 10, 6);
add_edge(graph, 11, 12, 10);
add_edge(graph, 12, 13, 5);
add_edge(graph, 13, 14, 1);
add_edge(graph, 15, 15, 2);
add_edge(graph, 16, 15, 4);
add_edge(graph, 16, 17, 6);
add_edge(graph, 17, 18, 2);
add_edge(graph, 19, 19, 6);

// meminta input titik awal dan tujuan dari pengguna
int start, end;
cout << "Masukkan titik awal: ";
cin >> start;
cout << "Masukkan titik tujuan: ";
cin >> end;

// mencari jalur terpendek dari start ke end menggunakan DFS
pair<vector<int>, int> result = dfs(graph, start, end);

// mencetak jalur terpendek
cout << "Jalur terpendek: ";
for (int i : result.first) {
    cout << i << " ";
}
cout << endl;

// mencetak bobot jalur terpendek
cout << "Bobot jalur terpendek: " << result.second << endl;

return 0;
}
