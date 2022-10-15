// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<c;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i);
            }
        }
        
        for(int i=0;i<c;i++){
            if(grid[r-1][i]==1){
                dfs(grid,r-1,i);
            }
        }
        
        for(int i=0;i<r;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
        }
        
        for(int i=0;i<r;i++){
            if(grid[i][c-1]==1){
                dfs(grid,i,c-1);
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
