// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>ans(n,INT_MAX);
	    ans[0]=0;
	    
	    for(int itr=1;itr<=n-1;itr++){
	        for(auto x:edges){
	            if(ans[x[0]]!=INT_MAX && ans[x[0]]+x[2] < ans[x[1]]){
	                ans[x[1]] = ans[x[0]] + x[2];
	            }
	        }
	    }
	    
	    for(auto x:edges){
	        if(ans[x[0]]!= INT_MAX && ans[x[0]]+x[2]< ans[x[1]]){
	            return 1;
	        }
	    }
	    return 0;
	}
};
