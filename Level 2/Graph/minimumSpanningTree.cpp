// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Pair{
    public:
    int v;
    int p;
    int wt;
    
    Pair(int v,int p,int wt){
        this->v = v;
        this->p = p;
        this->wt = wt;
    }
};

bool operator <(const Pair &p1,const Pair &p2){
    return p1.wt>p2.wt;
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>vis(V,false);
        priority_queue<Pair>pq;
        pq.push(Pair(0,-1,0));
        int ans=0;
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            if(vis[rem.v]){
                continue;
            }
            vis[rem.v] = true;
            
            ans += rem.wt;
            
            for(auto x:adj[rem.v]){
                if(vis[x[0]]==false){
                    pq.push(Pair(x[0],rem.v,x[1]));
                }
            }
        }
        return ans;
    }
};
