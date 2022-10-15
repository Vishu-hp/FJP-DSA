#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt)
    {
        this->v=v;
        this->wt=wt;
    }
};

class Pair{
    public:
    int v;
    int w;

    Pair(int v,int w){
        this->v=v;
        this->w=w;
    }
};

bool operator <(const Pair &a,const Pair &b){
    return a.w>b.w;
}

void prims(vector<vector<Edge>>&graph,int v){
    priority_queue<Pair>pq;
    vector<bool>vis(v,false);
    int ans=0;
    pq.push(Pair(0,0));
    while(pq.size()>0){
        Pair rem = pq.top();
        pq.pop();

        if(vis[rem.v]==true){
            continue;
        }
        vis[rem.v]=true;

        ans += rem.w;

        for(auto x:graph[rem.v]){
            if(vis[x.v]==false){
                pq.push(Pair(x.v,x.wt));
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge>> graph(vtces);
    int edges;cin>>edges;
    for(int i=0;i<edges;++i)
    {
        int v1;cin>>v1;
        int v2;cin>>v2;
        int wt;cin>>wt;
        graph[v1].push_back(Edge(v2,wt));
        graph[v2].push_back(Edge(v1,wt));
    }
    

    prims(graph,vtces);
    return 0;
}
