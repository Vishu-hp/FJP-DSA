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
  int wt = 0;

  Edge(int src, int nbr,int wt)
  {
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair{
  public:
  int v;
  string psf;
  int l;

  Pair(int v,string psf,int l){
    this->v=v;
    this->psf=psf;
    this->l=l;
  }
};

bool bfs(vector<Edge>graph[],vector<int>&vis,int s){
  queue<Pair>q;
  string tmp = to_string(s);
  q.push(Pair(s,tmp,0));
  while(!q.empty()){
    Pair rem = q.front();
    q.pop();

    if(vis[rem.v]!= 0){
        if(vis[rem.v] != rem.l){
          return false;
        }
    }
    vis[rem.v] = rem.l;
    for(auto x:graph[rem.v]){
      if(vis[x.nbr]== 0){
        q.push(Pair(x.nbr,rem.psf + to_string(x.nbr),rem.l+1));
      }
    }
  }
  return true;
}

int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<Edge> graph[vtces];
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v,w));
    graph[v].push_back(Edge(v, u,w));

  } 
  
  // write your code here
  vector<int>vis(vtces,0);
  bool ans=true;
  for(int i=0;i<vtces;i++){
    if(vis[i]==0){
      ans = bfs(graph,vis,i);
      if(ans==false){
        cout<<"false"<<endl;
        break;
      }
    }
  }

  if(ans){
    cout<<"true"<<endl;
  }
   return 0;
}
