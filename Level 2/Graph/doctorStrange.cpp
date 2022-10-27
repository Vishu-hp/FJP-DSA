// https://practice.geeksforgeeks.org/problems/doctor-strange2206/1

class Solution{
    public:
    
    vector<int>par;
    vector<int>disc;
    vector<int>low;
    
    vector<bool>ap;
    vector<bool>vis;
    
    int osrc;
    int count;
    int time;
    
    int doctorStrange(int N, int M, vector<vector<int>> & graph)
    {
         //Write your code here
         par.resize(N);
         disc.resize(N);
         low.resize(N);
         
         ap.resize(N);
         vis.resize(N);
         
         for(int i=0;i<N;i++){
             ap[i]=false;
             vis[i]=false;
         }
         
         osrc=0;
         time=0;
         count=0;
         
         vector<int>g[N];
         for(int i=0;i<M;i++){
             int u = graph[i][0];
             int v = graph[i][1];
             
             u--;
             v--;
             
             g[u].push_back(v);
             g[v].push_back(u);
         }
         
         dfs(g,osrc);
         
         
         int ans=0;
         for(int i=0;i<N;i++){
             if(ap[i]){
                 ans++;
             }
         }
         return ans;
    }
    
    void dfs(vector<int>g[],int curr){
        vis[curr] = true;
        disc[curr]=time;
        low[curr]=time;
        
        time++;
        
        for(auto nbr:g[curr]){
            if(vis[nbr]){
                if(par[curr] == nbr){
                    continue;
                }
                else{
                    low[curr] = min(low[curr],disc[nbr]);
                }
            }
            else{
                par[nbr] = curr;
                dfs(g,nbr);
                
                if(curr == osrc){
                    count++;
                    
                    if(count>=2){
                        ap[osrc] = true; 
                    }
                }
                else{
                    if(low[nbr]>=disc[curr]){
                        ap[curr]  = true;
                    }
                }
                
                low[curr] = min(low[curr],low[nbr]);
            }
        }
    }
};
