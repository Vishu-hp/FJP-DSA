// GREAT PROBLEM ON PARTITION ON STRING RECUSRION.
// GREAT PROBLEM FOR USING RECURSION FAITH.

class Solution {
public:
    bool check(string s){
        if(s.length()==0){
            return false;
        }
        int num=0, p=1;
        for(int i=s.length()-1;i>=0;i--){
            char ch = s[i];
            num += p*(ch-'0');
            p *= 2;
        }
        
        if(num==1){
            return true;
        }
        
        if(num==0){
            return false;
        }
        
        while(num!=1){
            if(num%5 != 0){
                return false;
            }
            num /= 5;
        }
        return true;
    }
    
    int solve(string s){
        int n = s.length();
        
        if(n==0){
            return 0;
        }

        if(n==1){
            if(s[0]=='1'){
                return 1;    
            }
            return INT_MAX;
        }
        
        int ans=INT_MAX;
        
        for(int i=1;i<=n;i++){
            string pf = s.substr(0,i);
            string sf;
            if(i!=n){
                sf = s.substr(i);
            }
            else{
                sf = "";
            }

            if(pf[0]=='0' || (i!=n && sf[0]=='0')){
                continue;
            }

            bool a1 = check(pf);
            bool a2 = check(sf);
            if(a1 && a2){
                return 2;
            }
            
            if(a1){
                int sa = solve(sf);
                if(sa!=INT_MAX){
                    ans = min(ans, 1 + sa);                             
                }
            }
        }
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        int ans = solve(s);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
