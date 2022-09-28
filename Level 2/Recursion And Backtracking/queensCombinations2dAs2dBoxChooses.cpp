#include<bits/stdc++.h>
using namespace std;

void solve(int qPsf,int tq,int r,int c,string asf){
    if(r == tq){
        if(qPsf == tq){
            cout<<asf<<endl;
        }
        return;
    }
    
    solve(qPsf+1,tq,c == tq-1?r+1:r,c == tq-1?0:c+1,c==tq-1?asf+"q\n":asf+"q");
    solve(qPsf,tq,c == tq-1?r+1:r,c == tq-1?0:c+1,c==tq-1?asf+"-\n":asf+"-");
}

int main(){
    int n;
    cin>>n;
    
    // vector<vector<int>>grid(n,vector<int>(n,0));
    solve(0,n,0,0,"");
    return 0;
}
