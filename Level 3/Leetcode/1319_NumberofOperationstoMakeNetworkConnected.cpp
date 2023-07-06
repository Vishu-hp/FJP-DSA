// GREAT DSU PROBLEM
// INTUTION: WE NEEDED GROUPS WHILE SOLVING PROBLEM. DSU FOR FINDING EXTRA EDGES.

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

    bool union_(int a,int b){
        int p1 = find(a);
        int p2 = find(b);

        if(p1==p2){
            return true;
        }

        if(rank[p1]>rank[p2]){
            par[p2]=p1;
            rank[p1] += rank[p2];
        }
        else{
            par[p1]=p2;
            rank[p2] += rank[p1];
        }
        return false;;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        par.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }

        int ans=0;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            bool ta = union_(u,v);
            if(ta){
                ans++;
            }
        }

        int comp=0;
        for(int i=0;i<n;i++){
            if(i == find(i)){
                comp++;
            }
        }

        if(ans >= comp-1){
            return comp-1;
        }

        return -1;
    }
};
