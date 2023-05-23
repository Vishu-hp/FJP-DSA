// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

// RECURSION & BACKTRACKING 

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    string swap(string &s,int i,int j){
        char ith = s[i];
        char jth = s[j];
        
        s[i] = jth;
        s[j] = ith;
        
        return s;
    }
    
    void solve(string &str,int k,string &ans){
        
        // int x = stoi(ans);
        // int y = stoi(str);
        
        // if(x<y){
        //     ans = str;
        // }
        
        if(str.compare(ans) > 0){
            ans=str;
        }
        
        if(k==0){
            return;
        }
        
        for(int i=0;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[i]<str[j]){
                    str =  swap(str,i,j);
                    solve(str,k-1,ans);
                    str = swap(str,i,j);
                }
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
        solve(str,k,ans);
        return ans;
    }
};

// ******************************************************************************************************************

// RECURSION & BACKTRACKING + OPTIMIZATION

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    string swap(string &s,int i,int j){
        char ith = s[i];
        char jth = s[j];
        
        s[i] = jth;
        s[j] = ith;
        
        return s;
    }
    
    void solve(string &str,int k,string &ans,int idx){
        
        if(str.compare(ans) > 0){
            ans=str;
        }
        
        if(k==0){
            return;
        }
        
        char mv = str[idx];
        for(int j=idx+1;j<str.length();j++){
            if(mv < str[j]){
                mv = str[j];
            }
        }
        
        if(mv!=str[idx]){
            k--;
        }
        
        for(int j=idx;j<str.length();j++){
             if (str[j] == mv) {
                str = swap(str,idx,j);
                solve(str, k, ans, idx + 1);
                str = swap(str,idx, j);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
        solve(str,k,ans,0);
        return ans;
    }
};
