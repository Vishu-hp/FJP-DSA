#include<bits/stdc++.h>
using namespace std;

int main(){
    //write your code here
    int n;
    cin>>n;
    vector<int>arr(n);
    int maxVal=INT_MIN;
    int minVal = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxVal=max(maxVal,arr[i]);
        minVal= min(minVal,arr[i]);
    }
    cout<< maxVal -minVal<<endl;
    return 0;
}
