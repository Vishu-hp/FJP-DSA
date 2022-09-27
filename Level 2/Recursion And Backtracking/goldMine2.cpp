// LEETCODE 1219 PATH WITH MAXIMUM GOLD
// ***************************************************
class Solution {
public:
    void solve(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int g,int &ans){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==true){
            ans = max(ans,g);
            return;
        }
        
        vis[i][j] = true;
        solve(grid,vis,i-1,j,g+grid[i][j],ans);
        solve(grid,vis,i+1,j,g+grid[i][j],ans);
        solve(grid,vis,i,j-1,g+grid[i][j],ans);
        solve(grid,vis,i,j+1,g+grid[i][j],ans);
        vis[i][j] = false;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
                    int tmpMax=0;
                    solve(grid,vis,i,j,0,tmpMax);
                    ans = max(ans,tmpMax);
                }
            }
        }
        
        return ans;
    }
};
