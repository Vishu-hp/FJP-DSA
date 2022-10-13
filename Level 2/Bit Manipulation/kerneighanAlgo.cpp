#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int rsbMask;
    int cnt=0;
    while(n!=0){
        rsbMask = n&(~n +1);
        n = n - rsbMask;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
