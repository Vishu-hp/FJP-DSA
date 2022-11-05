// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool check(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
        for(auto x:mp1){
            char a = x.first;
            int fr = x.second;
            
            if(mp2[a]!=fr){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        if(check(mp1,mp2)){
            return true;
        }
        
        int i=0,j=s1.length()-1;
        while(j<s2.length()){
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0) {
                mp2.erase(s2[i]);
            }
            i++;
            j++;
            mp2[s2[j]]++;
            
            if(check(mp1,mp2)){
                return true;
            }
        }
        return false;
    }
};
