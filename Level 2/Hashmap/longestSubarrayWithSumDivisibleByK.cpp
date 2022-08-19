#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &arr, int k) {
    // write your code here
    int n = arr.size();
    unordered_map<int,int>remMap;
    remMap[0] = -1;
    int sum=0;
    int ans = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        int r = sum%k;
        if(r<0){
            r+=k;
        }
        if(remMap.count(r)>0){
            ans = max(ans,i-remMap[r]);
        }
        else{
            remMap[r]=i;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << solution(arr, k) << endl;
}
