// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Pair{
    public:
    int v;
    int wsf;
    
    Pair(int v,int wsf){
        this->v=v;
        this->wsf = wsf;
    }
};

bool operator <(const Pair &p1,const Pair &p2){
    return p1.wsf>p2.wsf;
}

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dis(V,-1);
        priority_queue<Pair>pq;
        pq.push(Pair(S,0));
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            if(dis[rem.v]!=-1){
                continue;
            }
            dis[rem.v] = rem.wsf;
            
            for(auto x:adj[rem.v]){
                if(dis[x[0]]==-1){
                    pq.push(Pair(x[0],rem.wsf+x[1]));
                }
            }
        }
        return dis;
    }
};
