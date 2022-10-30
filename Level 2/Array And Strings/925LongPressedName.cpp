// https://leetcode.com/problems/long-pressed-name/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0]!= typed[0]){
            return false;
        }
        
        int p1=0,p2=0;
        int m = name.length();
        int n = typed.length();
        if(m > n){
            return false;
        }
        
        while(p1<m && p2<n){
            if(name[p1] == typed[p2]){
                p1++;
                p2++;
            }
            else{
                if(typed[p2] == name[p1-1]){
                    p2++;
                }
                else{
                    return false;
                }
            }
        }
        
        if(p1!= m){
            return false;
        }
        
        while(p2<n){
            if(typed[p2]!=name[m-1]){
                return false;
            }
            p2++;
        }
        return true;
    }
};
