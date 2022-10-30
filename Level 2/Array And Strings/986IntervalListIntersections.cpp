// https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        
        int p1=0,p2=0;
        int m = firstList.size();
        int n = secondList.size();
        vector<int>tmp(2);

        while(p1<m && p2<n){
            int s1 = firstList[p1][0];
            int e1 = firstList[p1][1];
            int s2 = secondList[p2][0];
            int e2 = secondList[p2][1];
            tmp.clear();
            tmp.resize(2);
             tmp[0] = max(s1,s2);
            tmp[1] = min(e1,e2);
            if(tmp[1]>=tmp[0]){
                ans.push_back(tmp);
            }
            
            if(e1<e2){
                p1++;
            }
            else{
                p2++;
            }
        }
        return ans;
    }
};
