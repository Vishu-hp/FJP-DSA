// https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int maxD=-1;
        for(int i=0;i<n;i++){
            maxD = max(maxD,trips[i][2]);
        }
        
        vector<int>pass(maxD+2,0);
        
        for(int i=0;i<n;i++){
            int v = trips[i][0];
            int s = trips[i][1];
            int e = trips[i][2];
            
            pass[s] += v;
            pass[e] -= v;
        }
        
        
        int pSum=0;
        for(int i=0;i<maxD+1;i++){
            pSum += pass[i];
            if(pSum>capacity){
                return false;
            }
        }
        return true;
    }
};
