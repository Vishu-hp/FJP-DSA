// AMAZING AMAZING PROBLEM.BASED ON RECURSION CONSIDERING PREFIX AND SUFFIX OF STRINGS
// INTUTION: FOR EVERY WORD WE CHECK IF A PREFIX OF STRING IS PRESENT IN DICTIONARY AND ITS SUFFIX IS ALSO PRESENT OR IF SUFFIX IS NOT PRESENT
// WE CHECK  RECURSIVELY FOR THAT IF IT IS CONCATENATION OF WORDS.

class Solution {
public:
    vector<string>ans;
    int dp[31];
    bool solve(unordered_set<string>&dic,string str,int idx){
        if(dp[idx]!=-1){
            return dp[idx];
        }

        string pf,sf;
        for(int l=1;l<=str.length()-idx;l++){
            pf = str.substr(idx,l);
            sf = str.substr(idx+l);
            if((dic.find(pf)!=dic.end() && dic.find(sf)!=dic.end()) || 
            (dic.find(pf)!=dic.end() && solve(dic,str,idx+l))){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string>ust(words.begin(), words.end());
        for(int i=0;i<n;i++){
            memset(dp,-1,sizeof(dp));
            if(solve(ust,words[i],0)){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
