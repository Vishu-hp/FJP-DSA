// https://practice.geeksforgeeks.org/problems/castle-run3644/1

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n = paths.size();
	    
	    for(int i=0;i<n;i++){
	        int deg=0;
	        for(int j=0;j<n;j++){
	            if(paths[i][j]==1){
	                deg++;
	            }
	        }
	        if(deg%2!=0){
	            return false;
	        }
	    }
	    
	   return true;
	}

};
