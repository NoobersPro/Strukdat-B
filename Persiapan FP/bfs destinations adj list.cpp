#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<pair<int, string>> adj[100];
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adj[v1].push_back(make_pair(v2, str));
}

void bfs(string startVertex, string destination){
	vector<bool> visited;
	visited.resize(V,false);
	queue<pair<int, string>> q;
	q.push(make_pair(0, startVertex));
	visited[0] = true;
	while(!q.empty()){
		for(auto const &i: adj[q.front().first]){
			if(!visited[i.first]){
				visited[i.first] = true;
				q.push(make_pair(i.first, i.second));
			}
		}
		cout << q.front().second << " ";
		const char *c = q.front().second.c_str();
		const char *d = destination.c_str();
		q.pop();
		if(strcmp(c, d) == 0) break;
	}
}

};
int main(){
	Graph g(20);

	g.addVertex("Rumah",0, 0);
    g.addVertex("Kos Putri",0, 1);
    g.addVertex("Masjid",0, 11);
    g.addVertex("Rumah Bersalin",0, 12);
    g.addVertex("Puskesmas",1, 2);
    g.addVertex("Hutan Kota",2, 3);
    g.addVertex("SMPN 8",3, 4);
    g.addVertex("Indomaret",3, 16);
    g.addVertex("Warung Bakso",4, 5);
    g.addVertex("Bengkel",5, 6);
    g.addVertex("Es Teh Indonesia",6, 7);
    g.addVertex("Depot Nasi Goreng",7, 8);
    g.addVertex("SPBU 2",7, 19);
	g.addVertex("Masjid",8, 9);
	g.addVertex("Barber",9, 10);
	g.addVertex("Barber",10, 10);
	g.addVertex("Rumah Bersalin",11, 12);
	g.addVertex("AHASS",12, 13);
	g.addVertex("SPBU",13, 14);
	g.addVertex("Hotel",15, 15);
	g.addVertex("Hotel",16, 15);
	g.addVertex("SMPN 9",16, 17);
    g.addVertex("SMKN 2",17, 18);
    g.addVertex("SPBU 2",19, 19);
    
	cout << "bfs destinations" << endl;
	g.bfs("Rumah", "Bengkel");
}