// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n  = s.length();
        int maxFreq=0;
        unordered_map<char,int>freq;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            freq[s[j]]++;
            maxFreq = max(maxFreq,freq[s[j]]);
            while((j-i+1)-maxFreq > k){
                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }
                i++;    
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
