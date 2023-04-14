// LEETCODE ----- 76. Minimum Window Substring

// OLD WAY (GIVES TLE NOW)
class Solution {
public:
    string minWindow(string s1, string s2) {
        unordered_map<char,int>mp1;
	unordered_map<char,int>mp2;
	for(int i=0;i<s2.length();i++){
		mp2[s2[i]]++;
	}
	int mc = 0;
	int dmc = s2.length();
	string ans="";
	int ansLen = INT_MAX;
	int i=0,j=0;
	while(j<s1.length()){
		mp1[s1[j]]++;
		if(mp2.count(s1[j])>0 && mp1[s1[j]]<=mp2[s1[j]]){
			mc++;
		}
	while(mc == dmc){
		if(ansLen>j-i+1){
			ansLen = j-i+1;
			ans = s1.substr(i,j-i+1);
		}
		mp1[s1[i]]--;
		if(mp2.count(s1[i])>0 && mp1[s1[i]]<mp2[s1[i]]){
			mc--;
		}
		if(mp1[s1[i]]==0){
			mp1.erase(s1[i]);
		}
		i++;
	}
		j++;
	}
	return ans;
    }
};


// *************************************************************************************************************
// NEW WAY

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
