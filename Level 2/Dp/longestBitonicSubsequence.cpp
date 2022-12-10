// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    
	    vector<int>lis(n,0);
	    
	    for(int i=0;i<n;i++){
	        int maxL = 0;
	        
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                maxL = max(maxL,lis[j]);
	            }
	        }
	        
	        lis[i] = maxL + 1;
	    }
	    
	    vector<int>lds(n,0);
	    
	    for(int i=n-1;i>=0;i--){
	        int maxL = 0;
	        
	        for(int j=i+1;j<n;j++){
	            if(nums[i]>nums[j]){
	                maxL = max(maxL,lds[j]);
	            }
	        }
	        
	        lds[i] = maxL + 1;
	    }
	    
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans= max(ans, lis[i]+lds[i]-1);
	    }
	    return ans;
	}
};
