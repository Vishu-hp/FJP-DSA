// RECURSION WAS EASY, BUT WHEN MEMOIZING WE MAY NEED TO REDUCE VARIABLES TO SAVE MEMORY

// RECURSION
class Solution {
public:

    int solve(vector<int>&rods,int idx,int s1,int s2){
        if(idx == rods.size()){
            if(s1==s2){
                return s1;
            }

            return INT_MIN;
        }

        int a1 = solve(rods,idx+1,s1+rods[idx],s2);
        int a2 = solve(rods,idx+1,s1,s2+rods[idx]);
        int a3 = solve(rods,idx+1,s1,s2);

        return  max({a1,a2,a3});
    }

    int tallestBillboard(vector<int>& rods) {
        return solve(rods,0,0,0);
    }
};

// MEMOIZATION WITH REDUCED VARIABLE
class Solution {
public:
    vector<unordered_map<int,int>>dp;

    int solve(vector<int>&rods,int idx,int diff){
        if(idx == rods.size()){
            if(diff==0){
                return 0;
            }

            return INT_MIN;
        }

        if(dp[idx].count(diff) > 0){
            return dp[idx][diff];
        }    

        int a1 = rods[idx] + solve(rods,idx+1,diff+rods[idx]);
        int a2 = solve(rods,idx+1,diff-rods[idx]);
        int a3 = solve(rods,idx+1,diff);

        return dp[idx][diff] =  max({a1,a2,a3});
    }

    int tallestBillboard(vector<int>& rods) {
        dp.resize(21);
        return solve(rods,0,0);
    }
};
