// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>>tab(N,vector<int>(N,0));
        int ans=0;
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<N;j++){
                if(i==N-1){
                    tab[i][j] = Matrix[i][j];
                }
                else{
                    int a = (i+1<N)?tab[i+1][j]:0;
                    int b = (i+1<N && j-1>=0)?tab[i+1][j-1]:0;
                    int c = (i+1<N && j+1<N)?tab[i+1][j+1]:0;
                    
                    tab[i][j] = Matrix[i][j] + max({a,b,c});
                }
                
                 ans=max(ans, tab[i][j]);
            }
        }
        return ans;
    }
};
