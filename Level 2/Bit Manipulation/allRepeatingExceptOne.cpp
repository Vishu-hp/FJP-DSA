#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans = ans^arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
