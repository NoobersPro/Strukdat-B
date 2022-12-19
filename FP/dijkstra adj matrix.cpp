#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

// menyimpan informasi tentang sebuah vertex
struct Vertex {
    int id;
    int distance;
    bool operator< (const Vertex& other) const {
        return distance > other.distance;
    }
};

// menyimpan informasi tentang sebuah graph
struct Graph {
    int num_vertices;
    int** adjacency_matrix;
};

// membuat graph baru dengan jumlah vertex yang diberikan
Graph create_graph(int num_vertices) {
    Graph graph;
    graph.num_vertices = num_vertices;

    // alokasi memori untuk adjacency matrix
    graph.adjacency_matrix = new int*[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        graph.adjacency_matrix[i] = new int[num_vertices];
    }

    // inisialisasi seluruh elemen adjacency matrix dengan INF
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph.adjacency_matrix[i][j] = INF;
        }
    }

    // menandai setiap vertex dengan jarak 0 dari dirinya sendiri
    for (int i = 0; i < num_vertices; i++) {
        graph.adjacency_matrix[i][i] = 0;
    }

    return graph;
}

// menambahkan edge dari u ke v dengan bobot w pada graph
void add_edge(Graph& graph, int u, int v, int w) {
    graph.adjacency_matrix[u][v] = w;
}

// mencari jalur terpendek dari vertex start ke vertex end menggunakan Dijkstra
pair<vector<int>, int> dijkstra(const Graph& graph, int start, int end) {
    // menyimpan jarak terpendek dari start ke setiap vertex
    vector<int> distance(graph.num_vertices, INF);
    // menyimpan vertex yang telah terpilih
    vector<bool> selected(graph.num_vertices, false);
    // menyimpan parent dari setiap vertex
    vector<int> previous(graph.num_vertices, -1);

    // memulai dengan start vertex
    distance[start] = 0;
    priority_queue<Vertex> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        // mengambil vertex dengan jarak terpendek
        Vertex u = pq.top();
		pq.pop();
		if (selected[u.id]) continue;
		selected[u.id] = true;
		if (u.id == end) break;

    // memperbarui jarak terpendek dari start ke setiap vertex yang terhubung dengan u
    for (int v = 0; v < graph.num_vertices; v++) {
        if (distance[v] > distance[u.id] + graph.adjacency_matrix[u.id][v]) {
            distance[v] = distance[u.id] + graph.adjacency_matrix[u.id][v];
            previous[v] = u.id;
            pq.push({v, distance[v]});
        }
    }
}

// membuat jalur terpendek dari start ke end
vector<int> path;
int current = end;
while (current != -1) {
    path.push_back(current);
    current = previous[current];
}

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

// mencari jalur terpendek dari start ke end menggunakan Dijkstra
pair<vector<int>, int> result = dijkstra(graph, start, end);

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