// https://leetcode.com/problems/restore-ip-addresses/

// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

class Solution {
public:
    bool isValid(string s){
    if(s[0] == '0'){
        return false;
    }
    
    int val = stoi(s);
    if(val>255){
        return false;
    }
    
    return true;
}
  
    void solve(string &s,int idx,int part,string asf,vector<string>&ans){
        if(idx >= s.length()){
            if(idx == s.length() && part == 4){
                ans.push_back(asf.substr(0,asf.length()-1));
            }
            return;
        }
        
        string nans = asf + s[idx] + ".";
        solve(s,idx+1,part+1,nans,ans);
        
        if(idx+2 <= s.length() && isValid(s.substr(idx,2))){
            string nans = asf + s.substr(idx,2) + ".";
            solve(s,idx+2,part+1,nans,ans);
        }
        
        if(idx+3 <= s.length() && isValid(s.substr(idx,3))){
            string nans = asf + s.substr(idx,3) + ".";
            solve(s,idx+3,part+1,nans,ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        solve(s,0,0,"",ans);
        return ans;
    }
};
