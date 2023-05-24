#include<bits/stdc++.h>
using namespace std;

int cntSetBits(int n){
    int rsbMask;
    int cnt=0;
    while(n!=0){
        rsbMask = n&(~n +1);
        n = n - rsbMask;
        cnt++;
    }
    return cnt;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    
    int v = n1^n2;

    int ans = cntSetBits(v);
    cout<<ans<<endl;

    return 0;
}
