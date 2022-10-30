// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
  static  bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int ans=1;
        sort(points.begin(),points.end(),sortcol);
        
        
        int e = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>e){
                ans++;
                e = points[i][1];
            }
            
        }
        return ans;
    }
};
