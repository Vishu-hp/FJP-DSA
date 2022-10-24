// https://practice.geeksforgeeks.org/problems/eulerian-path-in-an-undirected-graph5052/1

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
         vector<int>degree(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1){
                    degree[i]++;
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<N;i++){
            if(degree[i]%2 == 0){
                cnt++;
            }
        }
        
        if(cnt==N-2 || cnt==N){
            return 1;
        }
        return 0;
        
    }
};
