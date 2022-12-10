// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n,0);
	    int ans=0;
	    for(int i=0;i<n;i++){
	        int maxSum=0;
	        
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]){
	                if(dp[j]>maxSum){
	                    maxSum = dp[j];
	                }
	            }
	        }
	        
	        dp[i] = maxSum + arr[i];
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};
