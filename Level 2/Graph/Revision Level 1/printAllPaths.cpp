#include<bits/stdc++.h>

using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

void solve(vector<Edge>g[],int src,int des,vector<bool>&vis,string psf){
    if(src == des){
        cout<<psf+to_string(des)<<endl;
        return;
    }
    
    vis[src] = true;
    
    for(auto x:g[src]){
        if(vis[x.nbr]==false){
            solve(g,x.nbr,des,vis,psf+to_string(x.src));
        }
    }
    vis[src] = false;
}
    

int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here
    vector<bool>vis(vtces,false);
    solve(graph,src,dest,vis,"");
}
