#include <bits/stdc++.h> 
#include <list> 
using namespace std;  

#define INF 0x3f3f3f3f // The distance to other vertices is initialized as infinite  
// iPair ==> Integer Pair  
typedef std::pair<int, int> iPair;  

class compare
{
public:
    bool operator()(const iPair& lhs, const iPair& rhs)
    {
        return rhs.first < lhs.first;
    }

};

class Graph 
    {  
    int V; 
    list<iPair>* adj; // the list of pair to store vertex and its weight  
    
public:  

    Graph(int V) 
    {  
        this->V = V; 
        adj = new list<iPair>[V];  
    }  
    void addEdge(int u, int v, int w); 
    void shortestPathingraph(int s); 
    void showList();  

};  

void Graph::showList()  { 
    list <int> la;
    list<iPair>::iterator i;
    
    for (int v = 0; v < V; v++)  {
           cout << v ;	 
           for (i = adj[v].begin(); i != adj[v].end(); ++i)  {
                 cout << "-> " << (*i).first; 
                }
           cout<< ("\n");
     }
     cout << endl;
  } 


void Graph::addEdge(int u, int v, int w)   
{  
    adj[u].push_back(make_pair(v, w)); 
 
}  

void Graph::shortestPathingraph(int src) 
{  

    std::priority_queue<iPair, std::vector<iPair>, compare> pq;  
    vector<int> dist(V, INF); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0;  
    while (!pq.empty()) { 
        int u = pq.top().second;  
        pq.pop();  

		list<iPair>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {  

            int v = (*i).first;  
            int weight = (*i).second;  
  

            if (dist[v] > dist[u] + weight) {  
                dist[v] = dist[u] + weight;  
                pq.push(make_pair(dist[v], v));  
            }  
        }  
    }  
    printf("\nVertex \tDistance from Source\n");   
    for (int i = 0; i < V; ++i)  
        printf("%d \t\t %d\n", i, dist[i]); // The shortest distance from source  
}  
int main()  
{  
    int V = 20; 
    Graph g(V); 
    g.addEdge(0, 1, 1); // add root node with neighour vertex and weight  
    g.addEdge(0, 11, 1);  
    g.addEdge(0, 12, 1);  
    g.addEdge(1, 2, 1);  
    g.addEdge(2, 3, 1);  
    g.addEdge(3, 4, 1);  
    g.addEdge(3, 16, 1);  
    g.addEdge(4, 5, 1);  
    g.addEdge(5, 6, 1);  
    g.addEdge(6, 7, 1);  
    g.addEdge(7, 8, 1);  
    g.addEdge(7, 19, 1);  
    g.addEdge(8, 9, 1);  
    g.addEdge(9, 10, 1);
    g.addEdge(11, 12, 1);  
    g.addEdge(12, 13, 1);  
    g.addEdge(13, 14, 1);  
    g.addEdge(16, 15, 1);  
    g.addEdge(16, 17, 1);  
    g.addEdge(17, 18, 1);  
    
    g.showList();
    g.shortestPathingraph(0);  
    return 0;  
} 