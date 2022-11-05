// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            freq[s[j]]++;
            if(j-i+1 == freq.size()){
                ans = max(ans,j-i+1);
            }
            
            if(j-i+1 > freq.size()){
                while(j-i+1 > freq.size()){
                    freq[s[i]]--;
                    if(freq[s[i]] == 0){
                        freq.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
