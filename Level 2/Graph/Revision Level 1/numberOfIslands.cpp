#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&arr,int i,int j){
    if(i<0 || j<0 || i>=arr.size()|| j>=arr[0].size() || arr[i][j]==1){
        return;
    }
    
    arr[i][j]=1;
    
    dfs(arr,i-1,j);
    dfs(arr,i,j+1);
    dfs(arr,i+1,j);
    dfs(arr,i,j-1);
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
  
  int noi=0;
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(arr[i][j]==0){
              dfs(arr,i,j);
              noi++;
          }
      }
  }
  
  cout<<noi<<endl;
}
