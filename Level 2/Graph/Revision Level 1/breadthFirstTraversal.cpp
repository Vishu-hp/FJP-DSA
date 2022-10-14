#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};

class Pair{
    public:
    int v;
    string psf;
    
    Pair(int v,string psf){
        this->v = v;
        this->psf = psf;
    }
};

void bfs(vector<vector<Edge>>&g,int src){
    vector<bool>vis(g.size(),false);
    queue<Pair>q;
    q.push(Pair(src,to_string(src)));
    
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();
        
        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v] = true;
        cout<<rem.v<<"@"<<rem.psf<<endl;
        
        for(auto x:g[rem.v]){
            if(vis[x.nbr]==false){
                q.push(Pair(x.nbr,rem.psf+to_string(x.nbr)));
            }
        }
    }
    
    return;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  }

  int src;
  cin >> src;
  // write your code here
    bfs(graph,src);
  return 0;
}
