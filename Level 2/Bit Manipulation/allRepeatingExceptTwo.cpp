#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int xorArr=0;
    for(int i=0;i<n;i++){
        xorArr ^= arr[i];
    }
    
    int rsb = xorArr&(~xorArr +1);
    
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if((arr[i]&rsb) > 0){
            a = a^arr[i];
        }
        else{
            b = b^arr[i];
        }
    }
    
    if(a<b){
        cout<<a<<endl;
        cout<<b<<endl;    
    }
    else{
        cout<<b<<endl;
        cout<<a<<endl;
    }
    
    return 0;
}
