// GOOD GRAPH PROBLEM, AND GREAT USE OF DIJKSTRA ALGORITHM

class Solution {
public:
    vector<vector<pair<int,double>>>g;

    class Pair{
        public:
        int v;
        double psf;

        Pair(){}

        Pair(int v,double psf){
            this->v = v;
            this->psf = psf;
        }
    };

    class PairComp{
        public:

        bool operator()(const Pair &p1,const Pair &p2){
            return p1.psf < p2.psf;
        }
    };

    // DFS GIVES US TLE
    // double dfs(int s,int e,unordered_set<int>&vis){
    //     if(s==e){
    //         return 1.0;
    //     }

    //     vis.insert(s);

    //     double ans=-1.0;
    //     for(auto x:g[s]){
    //         int n =x.first;
    //         double p =x.second;

    //         if(vis.find(n) == vis.end()){
    //             double sa = dfs(n,e,vis);
    //             if(sa!= -1.0){
    //                 ans = max(ans, sa * p);
    //             }
    //         }
    //     }

    //     vis.erase(s);
    //     return ans;
    // }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        g.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            g[u].push_back({v,succProb[i]});
            g[v].push_back({u,succProb[i]});
        }

        // DIJKSTRA
        vector<double>prob(n,-1.0);
        prob[start] = 1.0;
        priority_queue<Pair,vector<Pair>,PairComp>pq;
        pq.push(Pair(start,1.0));
        

        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();

            if(rem.v == end){
                return rem.psf;
            }
            

            for(auto x:g[rem.v]){
                int n = x.first;
                double p = x.second;

                if(rem.psf * p > prob[n]){
                    prob[n] = rem.psf*p;
                    pq.push(Pair(n,prob[n]));
                }
            }
        }
        return 0.0;
    }
};
