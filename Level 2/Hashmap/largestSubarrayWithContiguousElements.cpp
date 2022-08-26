#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &arr){
    // write your code here
    int ans=1;
    for(int j=0;j<arr.size()-1;j++){
        unordered_set<int>ust;    
        int maxV=arr[j];
        int minV = arr[j];
        ust.insert(arr[j]);
        for(int i=j+1;i<arr.size();i++){
            if(ust.find(arr[i])!=ust.end()){
                break;
            }
            ust.insert(arr[i]);
            maxV = max(maxV,arr[i]);
            minV = min(minV,arr[i]);

            if(i-j+1 == maxV-minV+1){
                ans= max(ans,i-j+1);
            }
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
    cout << solution(arr) << endl;
}
