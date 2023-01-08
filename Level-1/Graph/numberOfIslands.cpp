#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&arr,int r,int c){
    if(r<0 || c<0 || r>=arr.size() || c>=arr[0].size() || arr[r][c]!=0){
        return;
    }

    arr[r][c]=1;

    dfs(arr,r-1,c);
    dfs(arr,r,c+1);
    dfs(arr,r+1,c);
    dfs(arr,r,c-1);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    //write your code here
    int numOfIslands = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                dfs(arr,i,j);
                numOfIslands++;
            }
        }
    }
    cout<<numOfIslands<<endl;

    return 0;
}
