#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;

	int adjM[20][20] ={
          {0, 0},
          {0, 0}
    };
	string place[20];
	
public:
Graph(int v){
	V = v;
}

void addVertex(string str, int v1, int v2){
	adjM[v1][v2] = 1;
	place[v2] = str;
}

void bfs(string startVertex, string destination){
	bool visited[20] = {false};
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int flag = 0;
		for(int i = 0; i<= 20; i++){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
		const char *d = destination.c_str();
		const char *c = place[q.front()].c_str();
		cout << place[q.front()] << " ";
		q.pop();
		if(strcmp(d, c)==0) break;
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
    g.addVertex("SPBU",7, 19);
	g.addVertex("Masjid",8, 9);
	g.addVertex("Barber",9, 10);
	g.addVertex("Rumah Bersalin",11, 12);
	g.addVertex("AHASS",12, 13);
	g.addVertex("SPBU 2",13, 14);
	g.addVertex("Hotel",16, 15);
	g.addVertex("SMPN 9",16, 17);
    g.addVertex("SMKN 2",17, 18);
    
	cout << "bfs destinations" << endl;
	g.bfs("Rumah", "Bengkel");

}
