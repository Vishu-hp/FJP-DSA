#include<bits/stdc++.h>
using namespace std;
void coinChange(vector<int>coins,int idx,int amtsf,int tamt,string asf){
    //write your code here
    if(idx == coins.size()){
        if(amtsf == tamt){
            cout<<asf+"."<<endl;
        }
        return;
    }
    
    if(amtsf+coins[idx]<=tamt){
        coinChange(coins,idx,amtsf+coins[idx],tamt,asf+to_string(coins[idx])+"-");    
    }
    
    coinChange(coins,idx+1,amtsf,tamt,asf);
}
int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amt;
    cin>>amt;
   
    coinChange(coins,0,0,amt,"");
}
