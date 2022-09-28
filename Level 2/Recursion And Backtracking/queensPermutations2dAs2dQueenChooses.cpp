#include<bits/stdc++.h>
using namespace std;

void solve(int cq,int tq,vector<vector<string>>&grid,int n){
    if(cq>tq){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=="-"){
                grid[i][j] = 'q'+to_string(cq);
                solve(cq+1,tq,grid,n);
                grid[i][j] = '-';
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<string>>grid(n,vector<string>(n,"-"));
    solve(1,n,grid,n);
}
