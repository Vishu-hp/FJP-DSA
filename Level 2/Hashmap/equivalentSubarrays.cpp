#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &arr, int k) {
  // write your code here
  unordered_set<int>ust;
  for(int i=0;i<arr.size();i++){
    ust.insert(arr[i]);
  }

  unordered_map<int,int>freq;
  int i=0,j=0;
  int ans=0;
  while(j<arr.size()){
    freq[arr[j]]++;
    
    while(freq.size()==ust.size()){
      ans += arr.size()-1-j+1;

      freq[arr[i]]--;
      if(freq[arr[i]]==0){
        freq.erase(arr[i]);
      }
      i++;
    }
    j++;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  unordered_set<int> set;
  for (int i = 0 ; i  < n; i++) {
    cin >> arr[i];
    set.insert(arr[i]);
  }
  cout << solution(arr, arr.size())<<endl;;
}
