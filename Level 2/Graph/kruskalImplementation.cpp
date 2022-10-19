#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ranker;

int find(int u)
{
    return parent[u] == u ? u : (parent[u] = find(parent[u]));
}

bool union_(int x,int y){
    int lx=find(x);
    int ly=find(y);
    
    if(lx==ly) return true;
    
    if (ranker[lx] > ranker[ly]) {
      parent[ly] = lx;
    } else if (ranker[lx] < ranker[ly]) {
      parent[lx] = ly;
    } else {
      parent[lx] = ly;
      ranker[ly]++;
    }
    
    return false;
}

int minCostToSupplyWater(int n,vector<vector<int>>& pipes){
    int k=pipes.size();
    vector<vector<int>>edges;
    for (int i = 0; i < pipes.size(); i++)
    {
        edges.push_back({pipes[i][0], pipes[i][1], pipes[i][2]});
    }

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    
    int ans=0;
    parent.resize(n+1);
    ranker.resize(n+1);
    
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
        ranker[i]=1;
    }
    
    for(int i=0;i<pipes.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
    
    
    bool flag=union_(u,v);
    if(flag==false){
        ans+=wt;
    }
    }
    return ans;
}


int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v,pipes);
    
}
