#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&boxes,int ci,int r){
    if(ci>r){
        for(int i=1;i<boxes.size();i++){
            cout<<boxes[i];
        }
        cout<<endl;
        return;
    }
    
    for(int i=1;i<boxes.size();i++){
        if(boxes[i]==0){
            boxes[i] = ci;
            solve(boxes,ci+1,r);
            boxes[i]=0;
        }
    }
}

int main(){
    int n,r;
    cin>>n>>r;
    
    vector<int>boxes(n+1,0);
    solve(boxes,1,r);
    return 0;
}
