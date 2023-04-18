#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&boxes,int ci,int ti,int lb){
    if(ci==ti){
        for(int i=1;i<boxes.size();i++){
            if(boxes[i]==1){
                cout<<"i";
            }
            else{
                cout<<"-";
            }
        }
        cout<<endl;
        return;
    }


    for(int i=lb+1;i<boxes.size();i++){
        if(boxes[i] == 0){
            boxes[i] = 1;
            solve(boxes,ci+1,ti,i);
            boxes[i] = 0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    
    vector<int>boxes(n+1,0);
    solve(boxes,0,r,0);
    return 0;
}
