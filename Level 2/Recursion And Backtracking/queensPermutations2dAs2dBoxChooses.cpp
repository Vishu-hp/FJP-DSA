#include<bits/stdc++.h>
using namespace std;

void solve(int r,int c,int qpsf,int tq,vector<int>&q,string asf){
    if(r == tq){
        if(qpsf == tq){
            cout<<asf<<endl;
            cout<<endl;
        }
        
        return;
    }
    
    for(int i=0;i<q.size();i++){
        if(q[i]==0){
            q[i]=1;
            solve(c==tq-1?r+1:r,c==tq-1?0:c+1,qpsf+1,tq,q,c==tq-1?asf+"q"+to_string(i+1)+"\n":asf+"q"+to_string(i+1)+"\t");
            q[i]=0;
        }
    }
    solve(c==tq-1?r+1:r,c==tq-1?0:c+1,qpsf,tq,q,c==tq-1?asf+"-"+"\n":asf+"-\t");
}

int main(){
    int n;
    cin>>n;
    
    vector<int>q(n,0);
    solve(0,0,0,n,q,"");
    return 0;
}
