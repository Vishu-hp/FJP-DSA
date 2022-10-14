#include<bits/stdc++.h>

using namespace std;
  
class Edge{
    public:
    int src;
    int nbr;

    Edge(int src,int nbr){
        this->src = src;
        this->nbr = nbr;
    }
};

void dfs(vector<Edge>*graph,int s,vector<int>&help,vector<bool>&vis){
    vis[s]=true;
    help.push_back(s);
    for(auto e:graph[s]){
        if(vis[e.nbr]==false){
            dfs(graph,e.nbr,help,vis);
        }
    }
    return;
}

int main(){
   int n;
   cin>>n;
      
   int k;
   cin>>k;
      
   // write your code here
    vector<Edge>graph[n];
    for(int i=0;i<k;i++){
        int s,n;
        cin>>s>>n;
        graph[s].push_back(Edge(s,n));
        graph[n].push_back(Edge(n,s));
    }

    vector<vector<int>>comps;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            vector<int>help;
            dfs(graph,i,help,vis);
            comps.push_back(help);
        }
    }

    int ans=0;
    for(int i=0;i<comps.size();i++){
        for(int j=i+1;j<comps.size();j++){
            ans += comps[i].size()*comps[j].size();
        }
    }
    cout<<ans<<endl;
   return 0;
 }
