#include<bits/stdc++.h>
using namespace std;

int cnt=1;
void solve(int cn,int tn,int ssf,int ts,vector<vector<int>>&v){
    if(cn>tn){
        if(ssf == ts){ 
          cout<<cnt<<". ";
          cnt++;
          
          for(auto x:v){
              if(x.size()!=0){
                cout<<"[";
                  for(int i=0;i<x.size()-1;i++){
                      cout<<x[i]<<", ";
                  }
                cout<<x[x.size()-1]<<"] ";    
              }
              
          }
          cout<<endl;
        }
        return;
    }
    
    for(int i=0;i<v.size();i++){
        if(v[i].size()==0){
            v[i].push_back(cn);
            solve(cn+1,tn,ssf+1,ts,v);
            v[i].pop_back();
            break;
        }
        else{
            v[i].push_back(cn);
            solve(cn+1,tn,ssf,ts,v);
            v[i].pop_back();
        }
    }
    return;
}

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<vector<int>>v(k);
    solve(1,n,0,k,v);
    return 0;
}
