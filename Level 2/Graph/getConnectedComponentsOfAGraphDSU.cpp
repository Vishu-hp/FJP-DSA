#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>ranker;

int find(int u){
    if(u == parent[u]){
        return u;
    }
    
    int gl = find(parent[u]);
    parent[u] = gl;
    return gl;
}

void union_(int x,int y){
    int lx = find(x);
    int ly = find(y);
    
    if(lx!=ly){
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
    }
}

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


int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  
  parent.resize(vtces);
  ranker.resize(vtces);
  
  for(int i=0;i<parent.size();i++){
      parent[i]=i;
      ranker[i]=1;
  }
  
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
    union_(v1,v2);
  }


  vector<vector<int>> comps;

  // write your code here
    map<int,vector<int>>ump;
    for(int i=0;i<parent.size();i++){
        ump[parent[i]].push_back(i);
    }
    
    for(auto x:ump){
        vector<int>tmp = x.second;
        comps.push_back(tmp);
    }

  cout << "[";
  for (int i = 0 ; i < comps.size() ; i++) {
    cout << "[";
    for (int j = 0 ; j < comps[i].size() ; j++) {
      if (j != comps[i].size() - 1)
        cout << comps[i][j] << ", ";
      else
        cout << comps[i][j];

    }
    cout << "]";
    if (i != comps.size() - 1)cout << ", ";
  }
  cout << "]";
}
