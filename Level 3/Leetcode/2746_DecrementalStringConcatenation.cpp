// RECURSION WAS DONE WITH INDEX AND STRING VARIABLE, BUT TO MEMOIZE IT WE TRY TO DO IT IN INT VARIABLE SO WE USED CHAR VARIABLE INSTED OF STRING SO IT BECOMES EASIER TO MEMOIZE
// AMAZING PROBLEM FOR MEMOIZATION

class Solution {
public:
    long long dp[1001][28][28];
    long long solve(vector<string>&words,int idx,char fc, char lc){
        if(idx == words.size()){
            return 0;
        }
    
        if(dp[idx][fc-'a'][lc-'a']!=-1){
            return dp[idx][fc-'a'][lc-'a'];
        }
        
        unsigned long long ans=INT_MAX;
        if(words[idx][words[idx].length()-1] == fc){
            ans = min(ans, words[idx].length()-1 + solve(words,idx+1,words[idx][0],lc));
        }   
        else{
            ans = min(ans, words[idx].length() + solve(words,idx+1,words[idx][0],lc));            
        }
        
        if(lc == words[idx][0]){
            ans = min(ans, words[idx].length()-1 + solve(words,idx+1,fc,words[idx][words[idx].length()-1]));
        }   
        else{
            ans = min(ans, words[idx].length() + solve(words,idx+1,fc,words[idx][words[idx].length()-1]));
        }
        
        return dp[idx][fc-'a'][lc-'a'] = ans;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        if(words.size()==1){
            return words[0].length();
        }
        
        memset(dp,-1,sizeof(dp));
        return words[0].length() + solve(words,1,words[0][0],words[0][words[0].length()-1]);
    }
};
