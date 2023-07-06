// GREAT DSU PROBLEM.

class Solution {
public:
    vector<int>par;
    vector<int>rank;

    int find(int n){
        if(n == par[n]){
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
            return ;
        }

        if(rank[p1]>rank[p2]){
            par[p2]=p1;
            rank[p1] += rank[p2];
        }
        else{
            par[p1]=p2;
            rank[p2] += rank[p1];
        }
        return;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i]=1;
        }

        for(int i=0;i<pairs.size();i++){
            int u = pairs[i][0];
            int v = pairs[i][1];

            union_(u,v);
        }

        unordered_map<int,vector<int>>mp1;
        for(int i=0;i<n;i++){
            mp1[find(i)].push_back(i);
        }

        for(auto x:mp1){
            vector<int>tmp  = x.second;
            string ts = "";
            for(auto y:tmp){
                ts += s[y];
            }
            sort(ts.begin(), ts.end());
            int idx=0;
            for(auto y:tmp){
                s[y] = ts[idx++];
            }
        }
        return s;
    }
};
