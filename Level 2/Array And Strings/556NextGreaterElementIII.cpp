// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    void swap(string &s,int i,int j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        
        return;
    }
    
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.length();
        int i=-1,j;
        for(int idx=l-2;idx>=0;idx--){
            if(s[idx]<s[idx+1]){
                i= idx;
                break;
            }
        }
        
        if(i==-1){
            return -1;
        }
        
        for(int idx=l-1;idx>i;idx--){
            if(s[idx]>s[i]){
                j = idx;
                break;
            }
        }
        
        swap(s,i,j);
        reverse(s.begin()+i+1,s.end());
        long long ans = stoll(s);
        
        if(ans <= pow(2,31)-1){
            return stoi(s);
        }
        return -1;
    }
};
