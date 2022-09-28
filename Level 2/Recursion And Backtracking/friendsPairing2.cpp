#include<bits/stdc++.h>
using namespace std;

int cnt=1;

void solve(int cf,int tf,vector<int>&f,string asf){
    if(cf>tf){
        cout<<to_string(cnt)+"."+asf<<endl;
        cnt++;
        return;
    }
    
    if(f[cf]==1){
        solve(cf+1,tf,f,asf);
    }
    else{
        f[cf]=1;
        solve(cf+1,tf,f,asf+"("+to_string(cf)+") ");
        for(int j=cf+1;j<f.size();j++){
            if(f[j]==0){
                f[j]=1;
                solve(cf+1,tf,f,asf+"("+to_string(cf)+","+to_string(j)+") ");
                f[j]=0;
            }
        }
        f[cf]=0;
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<int>f(n+1,0);
    solve(1,n,f,"");
    return 0;
}
