#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    if(n==1){
        return 0;
    }
    
    int x = solve(n-1,k);
    int ans = (x+k)%n;
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    
    cout<<solve(n,k)<<endl;
    return 0;
}
