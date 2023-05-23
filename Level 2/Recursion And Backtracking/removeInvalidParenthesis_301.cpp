// https://leetcode.com/problems/remove-invalid-parentheses/

// https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
  public:
    bool isValid(string str){
        int cnt = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
                cnt++;
            else if (str[i] == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    }
  
    vector<string> removeInvalidParentheses(string s) {
        // code here
        vector<string>ans;
        queue<string>q;
        unordered_set<string>vis;
        
        q.push(s);
        bool flag=false;
        
        while(q.size()>0){
            string tmp = q.front();
            q.pop();
            
            if(isValid(tmp)){
                ans.push_back(tmp);
                flag=true;
            }
            
            if(flag){
                continue;
            }
            
            for(int i=0;i<tmp.length();i++){
                if(tmp[i]=='(' || tmp[i]==')'){
                    string news = tmp.substr(0,i) + tmp.substr(i+1);
                    if(vis.find(news) == vis.end()){
                        q.push(news);
                        vis.insert(news);
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
