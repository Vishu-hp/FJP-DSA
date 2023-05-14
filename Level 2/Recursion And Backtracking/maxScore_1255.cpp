// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

class Solution {
public:
    int solve(vector<string>&words,vector<int>&farr,vector<int>&score,int idx){
        if(idx==words.size()){
            return 0;
        }

        int a1=0,a2;

        string tmp = words[idx];
        bool canInc = true;
        int scoreW = 0;
        for(int i=0;i<tmp.length();i++){
            char ch = tmp[i];
            farr[ch-'a']--;
            if(farr[ch-'a']<0){
                canInc = false;
            }
            scoreW += score[ch-'a'];
        }

        if(canInc){
            a1 = scoreW + solve(words,farr,score,idx+1);
        }

        for(int i=0;i<tmp.length();i++){
            char ch = tmp[i];
            farr[ch-'a']++;
        }

        a2 = solve(words,farr,score,idx+1);

        return max(a1,a2);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>farr(26,0);
        for(int i=0;i<letters.size();i++){
            char ch = letters[i];
            farr[ch-'a']++;
        }
        return solve(words,farr,score,0);
    }
};
