#include<bits/stdc++.h>
using namespace std;
void coinChange(vector<int>coins,int amtsf,int tamt,string asf){
    //write your code here
    if(amtsf == tamt){
        cout<<asf+"."<<endl;
        return;
    }

    for(int i=0;i<coins.size();i++){
        if(coins[i]+amtsf<=tamt){
            coinChange(coins,amtsf+coins[i],tamt,asf+to_string(coins[i])+"-");
        }
    }
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
    
    coinChange(coins,0,amt,"");
}
