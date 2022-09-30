#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,int cidx,int n,int ssf,int ts,vector<vector<int>>&v,vector<int>&subsetSum){
    if(cidx==n){
        if(ssf == ts){
            int sum = subsetSum[0];
            bool flag=true;
            for(int i=1;i<subsetSum.size();i++){
                if(subsetSum[i] == sum){
                    continue;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                for(auto x:v){
                    cout<<"[" ; 
                    for(int i=0;i<x.size();i++){
                        if(i!=x.size()-1){
                            cout<<x[i]<<", ";
                        }
                        else{
                            cout<<x[i]<<"] ";
                        }
                    }
                }
                cout<<endl;
            }
        }
        return;
    }
    
    for(int i=0;i<v.size();i++){
        if(v[i].size()==0){
            v[i].push_back(arr[cidx]);
            subsetSum[i] += arr[cidx];
            solve(arr,cidx+1,n,ssf+1,ts,v,subsetSum);
            v[i].pop_back();
            subsetSum[i] -= arr[cidx];
            break;
        }
        else{
            v[i].push_back(arr[cidx]);
            subsetSum[i] += arr[cidx];
            solve(arr,cidx+1,n,ssf,ts,v,subsetSum);
            v[i].pop_back();
            subsetSum[i] -= arr[cidx];
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int tsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tsum+=arr[i];
    }
    
    int k;
    cin>>k;
    
    if(k==1){
        cout<<"[";
        for(int i=0;i<n;i++){
            if(i!= n-1){
                cout<<arr[i]<<", ";
            }
            else{
                cout<<arr[i]<<"]";
            }
        }
        cout<<endl;
    }
    else{
        if(tsum%k!=0){
            cout<<"-1"<<endl;
        }
        else{
            vector<vector<int>>v(k);
            vector<int>subsetSum(k,0);
            solve(arr,0,n,0,k,v,subsetSum);    
        }    
    }
    
    
    
    
    return 0;
}
