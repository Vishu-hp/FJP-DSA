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

void dfs(vector<Edge>g[],vector<bool>&vis,int src,vector<int>&comp){
    vis[src] = true;
    comp.push_back(src);
    
    for(auto x:g[src]){
        if(vis[x.nbr]==false){
            dfs(g,vis,x.nbr,comp);
        }
    }
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
    vector<vector<int>>comps;
    
    vector<bool>vis(vtces,false);
    
    for(int i=0;i<vtces;i++){
        if(vis[i]==false){
            vector<int>comp;
            dfs(graph,vis,i,comp);
            comps.push_back(comp);
        }
    }
    
    if(comps.size()>1){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
}
