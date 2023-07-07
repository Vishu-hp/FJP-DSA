// GREAT PROBLEM ON RECURSION INVOLVING SUBSTRINGS
// INTUTION: WE NEED TO CHECK EVERY SUBSTRING ,IF IT IS WE NEED TO CHECK FORWARD FOR THIS SUBSTRING
// IF IT IS POSSIBLE TO SOLVE USING THIS SUBSTRING , SIMILARLY WE DO FOR ALL SUBSTRING RECURSIVELY.

class Solution {
public:
    vector<string>ans;

    void solve(string s,vector<string>&dic,int idx,string ssf){
        if(idx == s.length()){
            ans.push_back(ssf.substr(1));
            return;
        }

        string tmp;
        for(int l=1;l<=s.length()-idx;l++){
            tmp = s.substr(idx,l);
            if(find(dic.begin(),dic.end(),tmp)!=dic.end()){
                solve(s,dic,idx+l,ssf+" "+tmp);
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        solve(s,wordDict,0,"");
        return ans;
    }
};
