// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        
        sort(intervals.begin(),intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if(s<=end){
                end = max(end,e);
            }
            else{
                vector<int>tmpAns;
                tmpAns.push_back(start);
                tmpAns.push_back(end);
                ans.push_back(tmpAns);
                start = s;
                end= e;
            }
        }
        vector<int>tmpAns;
        tmpAns.push_back(start);
        tmpAns.push_back(end);
        ans.push_back(tmpAns);
        
        return ans;
    }
};
