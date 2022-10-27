// https://practice.geeksforgeeks.org/problems/articulation-point-1/1

class Solution {
  public:
    vector<int>par;
    vector<int>disc;
    vector<int>low;
    vector<bool>ap;
    vector<bool>vis;
    
    int osrc;
    int time;
    int count;
        
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        par.resize(V);
        disc.resize(V);
        low.resize(V);
        
        ap.resize(V);
        vis.resize(V);
        
        for(int i=0;i<V;i++){
            ap[i]=false;
            vis[i]=false;
        }
        
        osrc=0;
        time=0;
        count=0;
        
        dfs(adj,osrc);
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(ap[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0){
            ans.push_back(-1);
        }
        
        return ans;
    }
    
    void dfs(vector<int>adj[],int curr){
        vis[curr]=true;
        disc[curr]=time;
        low[curr]=time;
        
        time++;
        
        for(auto nbr:adj[curr]){
            if(vis[nbr]){
                if(nbr == par[curr]){
                    continue;
                }
                else{
                    low[curr] = min(low[curr],disc[nbr]); 
                }
            }
            else{
                par[nbr] = curr;
                dfs(adj,nbr);
                
                if(curr == osrc){
                    count++;
                    if(count>=2){
                        ap[osrc] = true;
                    }
                }
                else{
                    if(low[nbr] >= disc[curr]){
                        ap[curr] = true;
                    }
                }
                
                low[curr] = min(low[curr],low[nbr]);
            }
        }
        
    }
};
