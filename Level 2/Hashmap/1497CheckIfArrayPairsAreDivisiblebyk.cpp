class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>remFreq;
        for(int i=0;i<arr.size();i++){
            int rem = arr[i]%k;
            if(rem<0){
                rem += k;
            }
            remFreq[rem]++;
        }
        
        for(int i=0;i<arr.size();i++){
            int rem = arr[i]%k;
            if(rem<0){
                rem += k;
            }
            if(rem==0){
                if(remFreq[rem]%2!=0){
                    return false;
                }
            }
            else if(remFreq[rem]!= remFreq[k-rem]){
                return false;
            }
        }
        return true;
    }
};
