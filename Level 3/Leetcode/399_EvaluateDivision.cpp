// GREAT GRAPH AND DFS IMPLEMENTATION PROBLEM
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>g;

    double dfs(string c1,string c2,unordered_map<string,bool>&vis){
        vis[c1] = true;

        if(c1==c2){
            return 1.0;
        }

        for(auto x:g[c1]){
            string c = x.first;
            double d = x.second;

            if(vis.count(c) == 0){
                double ta = dfs(c,c2,vis);
                if(ta != -1.0){
                    return ta*d;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            string c1 = equations[i][0];
            string c2 = equations[i][1];

            g[c1].push_back({c2,values[i]});
            g[c2].push_back({c1, 1/values[i]});
        }

        vector<double>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            string c1 = queries[i][0];
            string c2 = queries[i][1];

            if(g.find(c1)==g.end() || g.find(c2)==g.end()){
                ans[i] = -1.0;
            }
            else if(c1==c2 ){
                ans[i] = 1.0;
            } 
            else{
                unordered_map<string,bool>vis;
                ans[i] = dfs(c1,c2,vis);
            }
        }
        return ans;
    }
};
