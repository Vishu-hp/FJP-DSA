// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome(string s){
        int li = 0;
        int ri = s.length()-1;
        
        while(li <= ri){
            if(s[li] != s[ri]){
                return false;
            }
            
            li++;
            ri--;
        }
        return true;
    }
    
    void solve(string s,vector<string>&tmp,vector<vector<string>>&ans){
        if(s.length() == 0){
            ans.push_back(tmp);
            return;
        }
        
        
        for(int i=0;i<s.length();i++){
            string news = s.substr(0,i+1);
            string ros = s.substr(i+1);
            
            if(isPalindrome(news)){
                tmp.push_back(news);
                solve(ros,tmp,ans);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tmp;
        solve(s,tmp,ans);
        return ans;   
    }
};
