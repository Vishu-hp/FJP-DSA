// AMAZING PROBLEM ON RECURSION.FIRST WE NEED TO SORT INTERVALS BY START TIME TO GET OPTIMAL SOLN.
// IF WE LEAVE AN INTERVAL WE MOVE TO NEXT INDEX, ELSE IF WE TAKE IT WE NEED TO THEN FIND NEARST INTERVAL WITH START TIME > LAST_EVENT_ENDTIME, WE CAN USE BINARY
// SEARCH FOR IT AS WELL TO SEARCH NEAREST INTERVAL WITH ABOVE CASE.

class Solution {
public:
    int solve(vector<vector<int>>&arr,int k,int idx,vector<vector<int>>&dp){
        if(idx == arr.size() || k==0){
            return 0;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int ans=INT_MIN;
        ans = max(ans, solve(arr,k,idx+1,dp));
        
        int j;
        for(j=idx+1;j<arr.size();j++){
            if(arr[j][0] > arr[idx][1]){
                break;
            }
        }

        ans = max(ans, arr[idx][2] + solve(arr,k-1,j,dp));

        return dp[idx][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        return solve(events,k,0,dp);
    }
};
