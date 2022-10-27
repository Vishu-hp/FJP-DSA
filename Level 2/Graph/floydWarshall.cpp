// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#define inf 99999

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	           if(matrix[i][j]==-1){
	               matrix[i][j] = inf ;
	           }
	        }
	    }
	    
	    
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][k]+matrix[k][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][k]+matrix[k][j];
	                }
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	           if(matrix[i][j]==inf){
	               matrix[i][j] = -1;
	           }
	        }
	    }
	    return;
	}
};
