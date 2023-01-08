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
  int n;
  string psf;

  Pair(int n,string psf){
    this->n = n;
    this->psf = psf;
  }
};

 

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
  queue<Pair>q;
  q.push(Pair(src,to_string(src)));
  vector<bool>vis(vtces,false);

  while(q.size()>0){
    Pair rem = q.front();
    q.pop();

    if(vis[rem.n]==true){
      continue;
    }

    vis[rem.n] = true;
    cout<<rem.n<<"@"<<rem.psf<<endl;

    for(auto e:graph[rem.n]){
      if(vis[e.nbr]==false){
        q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
      }
    }

  }

  return 0;
}
