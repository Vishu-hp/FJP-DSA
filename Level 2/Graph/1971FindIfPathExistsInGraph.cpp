// https://leetcode.com/problems/find-if-path-exists-in-graph/

vector<int>parent;
vector<int>ranker;

int find(int u){
    if(u == parent[u]){
        return u;
    }
    
    int gl = find(parent[u]);
    parent[u]=gl;
    return gl;
}

void union_(int x,int y){
    int lx= find(x);
    int ly = find(y);
    
    if(lx!=ly){
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
    }
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        ranker.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            ranker[i]=1;
        }
        
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            union_(u,v);
        }
        
        if(find(source) == find(destination)){
            return true;
        }
        return false;
    }
};
