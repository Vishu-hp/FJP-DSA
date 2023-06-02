class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>ump;
        for(auto x:t){
            ump[x]++;
        }
        int ans=INT_MAX;
        int cnt = ump.size();
        
        int i=0,j=0,start;
        while(j<s.length()){
            ump[s[j]]--;
            
            if(ump[s[j]] == 0){
                cnt--;
            }
            
            if(cnt==0){
                while(cnt==0){
                    if(ans > j-i+1){
                        ans = j-i+1;
                        start=i;
                    }
                        
                    ump[s[i]]++;
                    if(ump[s[i]]>0){
                        cnt++;
                    }
                    i++;
                }
            }
            j++;
        }
        
        if(ans!=INT_MAX){
            return s.substr(start,ans);
        }
        
        return "";
    }
};
