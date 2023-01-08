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


bool bfs(vector<vector<Edge>>&graph,int v,vector<bool>&vis,vector<int>&parent){
  queue<int>q;
  q.push(v);
  vis[v]=true;
  while(q.size()>0){
    int rem = q.front();
    q.pop();

    for(auto e:graph[rem]){
      if(vis[e.nbr]==true && parent[rem]!=e.nbr){
        return true;
      }

      if(vis[e.nbr]==false){
        q.push(e.nbr);
        vis[e.nbr]=true;
        parent[e.nbr]=rem;
      }
    }
  }
  return false;
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
 
 // write your code here

  vector<bool>vis(vtces,false);
  vector<int>parent(vtces,-1);
  bool flag=false;
  for(int i=0;i<vtces;i++){
    if(vis[i]==false){
      bool ans = bfs(graph,i,vis,parent);
      if(ans==true){
        flag = true;
        break;
      }
    }
  } 

  if(flag){
    cout<<"true"<<endl;
  }
  else{
    cout<<"false"<<endl;
  }
  return 0;
}
