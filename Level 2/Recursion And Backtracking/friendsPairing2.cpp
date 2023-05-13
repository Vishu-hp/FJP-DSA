// FRIENDS PAIRING (PRINTING ALL CONFIGURATIONS) - BACKTRACKING
#include<bits/stdc++.h>
using namespace std;

int cnt=1;

void solve(int cf,int tf,vector<int>&f,string asf){
    if(cf>tf){
        cout<<to_string(cnt)+"."+asf<<endl;
        cnt++;
        return;
    }
    
    if(f[cf]==1){
        solve(cf+1,tf,f,asf);
    }
    else{
        f[cf]=1;
        solve(cf+1,tf,f,asf+"("+to_string(cf)+") ");
        for(int j=cf+1;j<f.size();j++){
            if(f[j]==0){
                f[j]=1;
                solve(cf+1,tf,f,asf+"("+to_string(cf)+","+to_string(j)+") ");
                f[j]=0;
            }
        }
        f[cf]=0;
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<int>f(n+1,0);
    solve(1,n,f,"");
    return 0;
}


// FRIENDS PAIRING GFG - RECURSION + DP
class Solution
{
public:
    
    long long mod=1000000007;
    
    int solve(int n,int dp[]){
        if(n<=1){
            return 1;
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        long long a1 = solve(n-1,dp)%mod;
        long long a2 = (n>=2)?((n-1)*(solve(n-2,dp)%mod))%mod:0;
        
        dp[n] = (a1+a2)%mod;
        return (a1+a2)%mod;
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        int dp[10001]={0};
        return solve(n,dp);
    }
};
