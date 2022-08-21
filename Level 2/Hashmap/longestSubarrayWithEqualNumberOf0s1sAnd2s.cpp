#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v){
   //Write your code here
  int n =v.size();
  unordered_map<string,int>mp;
  mp["0#0"]=-1;
  int numZero=0;
  int numOne=0;
  int numTwo=0;

  int ans=0;
  for(int i=0;i<n;i++){
    if(v[i]==0){
      numZero++;
    }
    else if(v[i]==1){
      numOne++;
    }
    else{
      numTwo++;
    }

    int diff1 = numOne-numZero;
    int diff2 = numTwo-numOne;
    string str = to_string(diff1)+"#"+to_string(diff2);
    if(mp.count(str)>0){
      ans = max(ans,i-mp[str]);
    }
    else{
      mp[str]=i;
    }
  }
  return ans;
}


int main(){
    int n;cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << solution(arr) << endl;
}
