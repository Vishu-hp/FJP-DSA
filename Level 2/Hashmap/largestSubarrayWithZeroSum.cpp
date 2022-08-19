#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
  //write your code here
  int n=arr.size();
  int sum=0;
  unordered_map<int,int>mp;
  int ans=0;
  mp[0] = -1;
  for(int i=0;i<n;i++){
    sum += arr[i];
    if(mp.count(sum)>0){
      ans = max(ans,i-mp[sum]);
    }
    else{
      mp[sum]=i;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  };

  cout << solution(arr);
  return 0;
}
