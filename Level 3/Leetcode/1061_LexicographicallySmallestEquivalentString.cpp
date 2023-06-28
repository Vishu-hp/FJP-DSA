// GOOD DSU PROBLEM.
// INTUTION- WE HAVE TO CREATE GROUPS TO SOLVE PROBLEM

class Solution {
public:
    vector<int>par;

    int find(int n){
        if(par[n]==n){
            return n;
        }

        int p = find(par[n]);
        par[n] = p;
        return p;
    }

    void union_(int a,int b){
        int p1 = find(a);
        int p2 = find(b);

        if(p1==p2){
            return;
        }

        if(p1<p2){
            par[p2]=p1;
        }
        else{
            par[p1]=p2;
        }

        return;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26);

        for(int i=0;i<26;i++){
            par[i] = i;
        }

        for(int i=0;i<s1.length();i++){
            union_(s1[i]-'a',s2[i]-'a');
        }

        string ans=baseStr;
        for(int i=0;i<baseStr.length();i++){
            int p = find(baseStr[i]-'a');
            ans[i] = char(p+97);
        }
        return ans;
    }
};
