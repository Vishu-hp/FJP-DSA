// GOOD RECURSION PROBLEM USING FAITH

class Solution {
public:
    unordered_map<string,vector<int>>dp;
    vector<int> solve(string expression){
        if(dp.count(expression) > 0){
            return dp[expression];
        }
        
        vector<int>ans;
        int n = expression.size();

        for(int i=0;i<n;i++){
            char ch = expression[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int>la = solve(expression.substr(0,i));
                vector<int>ra = solve(expression.substr(i+1));

                for(auto x:la){
                    for(auto y:ra){
                        if(ch == '+'){
                            ans.push_back(x+y);
                        }
                        else if(ch == '-'){
                            ans.push_back(x-y);
                        }
                        else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }

        if(ans.size()==0){
            ans.push_back(stoi(expression));
        }

        return dp[expression] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        
        return solve(expression);
    }
};
