#include<bits/stdc++.h>
using namespace std;
void coinChange(vector<int>coins,int amtsf,int tamt,string asf,vector<bool>used){
    //write your code here
    if(amtsf == tamt){
        cout<<asf+"."<<endl;
        return;
    }

    for(int i=0;i<coins.size();i++){
        if(used[i]==false && coins[i]+amtsf<=tamt){
            used[i]=true;
            coinChange(coins,amtsf+coins[i],tamt,asf+to_string(coins[i])+"-",used);
            used[i] = false;
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
    vector<bool>used(n);
    for(int i=0;i<n;i++){
        used[i]=false;
    }
    coinChange(coins,0,amt,"",used);
}
