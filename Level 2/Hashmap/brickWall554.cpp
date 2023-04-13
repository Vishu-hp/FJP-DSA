class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int,int>ump;
        int maxB = 0;
        for(auto bs:wall){
            int ps=0;
            for(int i=0;i<bs.size()-1;i++){
                ps += bs[i];
                ump[ps] += 1;
                maxB= max(maxB,ump[ps]);
            }
        }
        return n-maxB;
    }
};
