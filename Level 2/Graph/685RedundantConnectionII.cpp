// https://leetcode.com/problems/redundant-connection-ii/

class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>ranker;
        
        DSU(int n){
            parent.resize(n);
            ranker.resize(n);
            
            for(int i=0;i<n;i++){
                parent[i] = i;
                ranker[i] = 1;
            }
        }
        
        int find(int u){
            if(parent[u]==u){
                return u;
            }
            
            int gl = find(parent[u]);
            parent[u] = gl;
            return gl;
        }
        
        bool union_(int x,int y){
            int lx = find(x);
            int ly = find(y);
            
            if(lx==ly){
                return true;
            }
            
            if(ranker[lx]>ranker[ly]){
                parent[ly] = lx;
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
    };
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU obj(n+1);
        
        vector<int>arr(n+1,-1);
        
        int p1=-1,p2=-1;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(arr[v]==-1){
                arr[v] = i;
            }
            else{
                p1 = arr[v];
                p2=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
             int  u =edges[i][0];
            int v = edges[i][1];
            
            if(p2==i){
                continue;
            }
            bool flag = obj.union_(u,v);
            if(flag){
                if(p1==-1){
                    return edges[i];
                }
                else{
                    return edges[p1];
                }
            }
        }
        return edges[p2];
    }
};
