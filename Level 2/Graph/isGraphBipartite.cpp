// https://leetcode.com/problems/is-graph-bipartite/

class Pair{
    public:
    int v;
    int l;
    Pair(int v,int l){
        this->v=v;
        this->l=l;
    }
};

class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int>&vis,int s){
        queue<Pair>q;
        q.push(Pair(s,0));
        while(!q.empty()){
            Pair rem=q.front();
            q.pop();
            
            if(vis[rem.v]!=-1){
                if(rem.l != vis[rem.v]){
                    return false;
                }
            }
            
            vis[rem.v]=rem.l;
            for(auto x:graph[rem.v]){
                if(vis[x]==-1){
                    q.push(Pair(x,rem.l+1));                
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
           if(vis[i]==-1){
               bool ans=check(graph,vis,i);
               if(!ans){
                   return false;
               }
           }
        }
        return true;
    }
};
