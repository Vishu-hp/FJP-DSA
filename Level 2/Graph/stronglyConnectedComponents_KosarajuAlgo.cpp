// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    
    void dfs(vector<int>adj[],int s,vector<bool>&vis,stack<int>&st){
        vis[s] = true;
        
        for(auto x:adj[s]){
            if(vis[x]==false){
                dfs(adj,x,vis,st);
            }
        }
        
        st.push(s);
    }
    
    void dfs2(vector<int>adj[],int s,vector<bool>&vis){
        vis[s] = true;
        
        for(auto x:adj[s]){
            if(vis[x]==false){
                dfs2(adj,x,vis);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int>st;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(adj,i,vis,st);
            }
        }
        
        vector<int>g[V];
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                g[x].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++){
            vis[i]=false;
        }
        
        int cnt=0;
        while(st.size()>0){
            int tp = st.top();
            st.pop();
            
            if(vis[tp]==false){
                dfs2(g,tp,vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};
