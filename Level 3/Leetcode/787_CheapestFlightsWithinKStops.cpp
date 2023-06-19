// DFS + MEMOIZATION

class Solution {
public:
    vector<vector<pair<int,int>>>g;
    int dp[101][101];
    int solve(int src,int dst,int k){
        if(src == dst){
            return 0;
        }

        if(k < 0){
            return 1e9;
        }

        if(dp[src][k] != -1){
            return dp[src][k];
        }

        int ans=1e9;
        for(auto x:g[src]){
            ans = min(ans, x.second + solve(x.first,dst,k-1)) ;
        }
        return dp[src][k] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        g.resize(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            pair<int,int>tmp;
            tmp.first = v;
            tmp.second = w;

            g[u].push_back(tmp);
        }

        memset(dp,-1,sizeof(dp));
        int ans = solve(src,dst,k); 
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
