#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

vector<int>parent;
vector<int>ranker;

int find(int u){
    return (u == parent[u])?u:parent[u]=find(parent[u]);
}

bool union_(int x,int y){
    int lx = find(x);
    int ly = find(y);
    
    if(lx==ly) return true;
    
    if(ranker[lx]>ranker[ly]){
        parent[ly]=lx;
    }
    else if(ranker[ly]>ranker[lx]){
        parent[lx]=ly;
    }
    else{
        parent[lx]=ly;
        ranker[ly]++;
    }
    return false;
}

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


int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());

parent.resize(vtces+1);
ranker.resize(vtces+1);

for(int i=0;i<vtces+1;i++){
    parent[i]=i;
    ranker[i]=1;
}

  int edges;
  cin >> edges;
bool flag=true;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
    
    if(flag==true){
     bool ans = union_(u,v);
        if(ans==true){
            cout<<"true"<<endl;
            flag=false;
        }   
    }
     
  }

// write your code here

   
    
    if(flag){
        cout<<"false"<<endl;
    }
  return 0;
}
