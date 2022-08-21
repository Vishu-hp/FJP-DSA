#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &arr, int n) {
  // write your code here
  unordered_map<string,int>mp;
  mp["0#0"]=1;
  int numZero=0;
  int numOne=0;
  int numTwo=0;

  int ans=0;
  for(int i=0;i<n;i++){
    if(arr[i]==0){
      numZero++;
    }
    else if(arr[i]==1){
      numOne++;
    }
    else{
      numTwo++;
    }

    int diff1 = numOne-numZero;
    int diff2 = numTwo-numOne;
    string str = to_string(diff1)+"#"+to_string(diff2);
    if(mp.count(str)>0){
      ans += mp[str];
      mp[str]++;
    }
    else{
      mp[str]=1;
    }
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << solution(arr, n);
}
