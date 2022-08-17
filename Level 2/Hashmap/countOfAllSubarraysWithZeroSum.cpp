#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr) {
  //write your code here
  int sum=0;
  int ans=0;
  unordered_map<int,int>freq;
  freq[0]=1;
  for(int i=0;i<arr.size();i++){
    sum += arr[i];
    if(freq.count(sum)>0){
      ans += freq[sum];
      freq[sum]++;
    }
    else{
      freq[sum] = 1;
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

  cout << solution(arr)<<endl;
  return 0;
}
