class Solution {
  public:
    string psf="";
    void dfs(vector<vector<int>>&grid,int i,int j){
        
        grid[i][j]=0;
        if(i-1>=0 && grid[i-1][j]==1){
            psf+= "u";
            dfs(grid,i-1,j);
            psf+= "#";
        }
         if(j+1<grid[0].size() && grid[i][j+1]==1){
            psf+= "r";
            dfs(grid,i,j+1);
            psf+= "#";
        }
        if(i+1<grid.size() && grid[i+1][j]==1){
            psf+= "d";
            dfs(grid,i+1,j);
            psf+= "#";
        }
        if(j-1>=0 && grid[i][j-1]==1){
            psf+= "l";
            dfs(grid,i,j-1);
            psf+= "#";
        }
        
    }
    
   
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        unordered_set<string>ump;
        
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                  ump.insert(psf);
                    psf="";
                }
            }
        }
        return ump.size();

    }
};
