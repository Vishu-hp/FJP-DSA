#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int idx, int n){
    // write your code here
    if(idx==n){
        return INT_MIN;
    }
    int faith = max(arr,idx+1,n);
    int ans=arr[idx];
    if(ans<faith){
        ans=faith;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
