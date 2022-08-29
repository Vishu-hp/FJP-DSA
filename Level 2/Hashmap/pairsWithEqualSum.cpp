#include <bits/stdc++.h>

using namespace std;

bool solution(vector<int>& arr, int n) {
  // write your code here
  unordered_set<int>ust;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int sum = arr[i]+arr[j];

        if(ust.find(sum)==ust.end()){
          ust.insert(sum);
        }
        else{
          return true;
        }
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bool ans = solution(arr, n);
  if (ans == 0) {
    cout << "false";
  } else {
    cout << "true";
  }
}
