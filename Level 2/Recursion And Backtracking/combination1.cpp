#include<bits/stdc++.h>
using namespace std;

void solve(int cb,int tb,int objpsf,int tobj,string config){
    if(cb>tb){
        if(objpsf == tobj){
            cout<<config<<endl;
        }
        return;
    }
    
    solve(cb+1,tb,objpsf+1,tobj,config+"i");
    solve(cb+1,tb,objpsf,tobj,config+"-");
}

int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    
    solve(1,n,0,r,"");
    return 0;
}
