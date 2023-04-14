class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        
        unordered_map<string,int>ump;
        for(auto s:cpdomains){
            int idx = s.find(" ");
            int num = stoi(s.substr(0,idx));
            string str = s.substr(idx+1);
            
            ump[str] += num;
            for(int i=0;i<str.length();i++){
                if(str[i]=='.'){
                    ump[str.substr(i+1)] += num;
                }
            }
        }
        
        for(auto x:ump){
            string s = to_string(x.second) + " " + x.first;
            ans.push_back(s);
        }
        return ans;
    }
};
