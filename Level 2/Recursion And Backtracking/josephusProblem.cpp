// NADOS SOLUTION
#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    if(n==1){
        return 0;
    }
    
    int x = solve(n-1,k);
    int ans = (x+k)%n;
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    
    cout<<solve(n,k)<<endl;
    return 0;
}


// GFG SOLUTION(QUESTION STATEMENT IS A LITTLE DIFFERENT (0 TO N-1) AND (1 TO N)
class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       if(n==1){
           return 1;
       }
       
       int x = josephus(n-1,k);
       int ans = (x+k)%n;
       if(ans==0){
           return n;
       }
       return ans;
    }
};
