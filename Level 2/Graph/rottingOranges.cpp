// https://leetcode.com/problems/rotting-oranges/

class Pair{
    public:
    int r;
    int c;
    int t;
    
    Pair(int r,int c,int t){
        this->r=r;
        this->c=c;
        this->t=t;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int fresh=0,rot=0;
        queue<Pair>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push(Pair(i,j,0));
                    rot++;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }     
        
        int ans=0;
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                Pair rem = q.front();
                q.pop();
                
                int r=rem.r;
                int c=rem.c;
                
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    fresh--;
                    q.push(Pair(r-1,c,rem.t+1));
                }
                
                if(c+1<col && grid[r][c+1]==1){
                    fresh--;
                    grid[r][c+1]=2;
                    q.push(Pair(r,c+1,rem.t+1));
                }
                
                if(r+1<row && grid[r+1][c]==1){
                    fresh--;
                    grid[r+1][c]=2;
                    q.push(Pair(r+1,c,rem.t+1));
                }
                
                if(c-1>=0 && grid[r][c-1]==1){
                    fresh--;
                    grid[r][c-1]=2;
                    q.push(Pair(r,c-1,rem.t+1));
                }
            }
            ans++;
        }
        
        
        if(fresh==0){
            if(rot!=0){
                return ans-1;    
            }
            else{
                return 0;
            }    
        }
        else{
            return -1;
        }
    }
};
