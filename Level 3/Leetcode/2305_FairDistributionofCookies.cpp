// GOOD RECURSION PROBLEM ON SUBSETS

class Solution {
public:
    int solve(vector<int>&cookies,int idx,vector<int>&ss){
        if(idx == cookies.size()){
            int sa=INT_MIN;
            for(int i=0;i<ss.size();i++){
                sa = max(sa,ss[i]);
            }
            return sa;
        }


        int ans = INT_MAX;
        for(int i=0;i<ss.size();i++){
            ss[i] += cookies[idx];
            ans = min(ans,  solve(cookies,idx+1,ss));
            ss[i] -= cookies[idx];
        }
        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n =cookies.size();
        vector<int>ss(k,0);
        return solve(cookies,0,ss);
    }
};
