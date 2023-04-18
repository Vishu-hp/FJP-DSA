#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&boxes,vector<int>&items,int cb,int tb,int cip,int ti){
    if(cb>tb){
        if(cip==ti){
            for(int i=1;i<boxes.size();i++){
                cout<<boxes[i];
            }
            cout<<endl;
        }
        return;
    }

    for(int i=1;i<=ti;i++){
        if(items[i] == 0){
            boxes[cb] = i;
            items[i]=1;
            solve(boxes,items,cb+1,tb,cip+1,ti);
            items[i]=0;
            boxes[cb] = 0;
        }
    }

    solve(boxes,items,cb+1,tb,cip,ti);
}

int main(){
    int n,r;
    cin>>n>>r;
    
    vector<int>boxes(n+1,0);
    vector<int>items(r+1,0);

    solve(boxes,items,1,n,0,r);
    return 0;
}
