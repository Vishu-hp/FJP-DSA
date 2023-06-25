// GOOD DP PROBLEM

class Solution {
public:
    long long dp[101][201];
    long long mod = 1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel < 0){
            return 0;
        }

        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }

        long long ta=0;
        if(start == finish){
            ta++;
        }

        for(int i=0;i<locations.size();i++){
            if(i!=start){
              ta = (ta +  solve(locations,i,finish,fuel - 
                abs(locations[start]-locations[i])))%mod;
            }
        }
        return dp[start][fuel] = ta;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel);
    }
};
