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

   void printAllPaths(vector<Edge>*graph,vector<bool>&vis,int vtx,int des,string psf){
      if(vtx==des){
         cout<<psf<<endl;
         return;
      }

      vis[vtx]=true;
      for(auto e:graph[vtx]){
         if(vis[e.nbr]==false){
            printAllPaths(graph,vis,e.nbr,des,psf+to_string(e.nbr));
         }
      }
      vis[vtx]=false;
   }
   
   
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }

      int src;
      cin>>src;
      int dest;
      cin>>dest;
      // write your code here
      vector<bool>vis(vtces,false);

      string psf = to_string(src);
      printAllPaths(graph,vis,src,dest,psf);
    }
