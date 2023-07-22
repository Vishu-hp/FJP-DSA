//  DIGIT DP PROBLEM. IMPLEMENTATION IS IMPORTANT

class Solution {
public:
    const int mod = 1e9+7;
    int dp[23][401][2][2];

    int solve(string s1,string s2,int idx,int x,bool t1, bool t2){
        if(idx == s2.length()){
            if(x<0){
                return 0;
            }
            return 1;
        }

        if(x<0){
            return 0;
        }

        if(dp[idx][x][t1][t2]!=-1){
            return dp[idx][x][t1][t2];
        }

        int lb = (t1)?s1[idx] - '0':0;
        int ub = (t2)?s2[idx] - '0':9;
        int ans=0;
        for(int i=lb;i<=ub;i++){
            ans = (ans%mod + solve(s1,s2,idx+1,x-i, t1 & (i==lb), t2 & (i==ub)) %mod )%mod;
        }
        return dp[idx][x][t1][t2] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        int diff = num2.length()-num1.length();
        string nn1 = string(diff, '0') + num1;

        memset(dp,-1,sizeof(dp));

        int a1 = solve(nn1,num2,0,max_sum,1,1);
        int a2 = solve(nn1,num2,0,min_sum-1,1,1);

        int ans = (a1-a2)%mod;

        if(ans<0){
            ans += mod;
        }
        return ans;
    }
};
