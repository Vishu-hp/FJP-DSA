// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r = s.length()-1;
        
        while(l<r){
            if(isalpha(s[l]) == false && isdigit(s[l])==false){
                l++;
                continue;
            }
            
            if(isalpha(s[r]) == false && isdigit(s[r]) == false){
                r--;
                continue;
            }
            char a = s[l];
            a = tolower(a);
            char b = s[r];
            b = tolower(b);
                
            if(a!=b){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
