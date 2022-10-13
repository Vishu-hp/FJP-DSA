#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int mask = (~n)+1;
    int ans = n&mask;
    string ansStr="";
    
    while(ans){
        if(ans&1){
            ansStr = '1'+ansStr;
        }
        else{
            ansStr = '0'+ansStr;
        }
        ans = ans>>1;
    }
    cout<<ansStr<<endl;
    return 0;
}
