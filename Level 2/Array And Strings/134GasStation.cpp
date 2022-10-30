// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0 , sumCost=0;
        for(int i=0;i<gas.size();i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        
        if(sumCost > sumGas){
            return-1;
        }
        
        int total=0 , ans=0;
        for(int i=0;i<gas.size();i++){
            total += (gas[i]-cost[i]);
            
            if(total<0){
                total = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};
