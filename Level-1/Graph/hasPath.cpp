#include<bits/stdc++.h>
using namespace std;
class Edge {
      public:
         int src;
         int nbr;
         int wt;

   Edge(int src, int nbr, int wt){
      this->src = src;
      this->nbr = nbr;
      this->wt = wt;
   }
};

bool solve(vector<Edge>graph[],int src,int des,vector<bool>&vis){
   if(src==des){
      return true;
   }

   vis[src]=true;

   for(auto x:graph[src]){
      if(vis[x.nbr]==false){
         bool subAns = solve(graph,x.nbr,des,vis);
         if(subAns){
            return true;
         }
      }
   }
   return false;
}

int main(){
   int v,e;
   cin>>v>>e;

   vector<Edge> graph[v];
   for(int i=0;i<e;i++){
      int s,n,w;
      cin>>s>>n>>w;

      graph[s].push_back(Edge(s,n,w));
      graph[n].push_back(Edge(n,s,w));
   }

   int src,des;
   cin>>src>>des;
   vector<bool>vis(v,false);


   bool ans = solve(graph,src,des,vis);
   if(ans){
      cout<<"true"<<endl;
   }
   else{
      cout<<"false"<<endl;
   }
   return 0;
}
