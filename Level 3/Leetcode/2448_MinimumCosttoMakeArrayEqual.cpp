// GREAT IMPLEMENTATION OF PREFIX SUM

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
         
        vector<pair<long long,long long>>arr;
        vector<long long>prefc(n,0);
        for(int i=0;i<n;i++){
            pair<long long,long long>p;
            p.first = nums[i];
            p.second = cost[i];
            arr.push_back(p);
        }
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            if(i==0){
                prefc[i] = arr[i].second;
            }
            else{
                prefc[i] = 1LL*prefc[i-1] + arr[i].second;
            }
        }

        long long tc=0;
        for(int i=1;i<n;i++){
            tc += 1LL*arr[i].second * (arr[i].first - arr[0].first);
        }

        long long ans=tc;
        for(int i=1;i<n;i++){
            long long diff = arr[i].first - arr[i-1].first;
            tc += 1LL*prefc[i-1] * diff;
            tc -= 1LL*diff*(prefc[n-1] - prefc[i-1]);

            ans = min(ans, tc);
        }
        return ans;
    }
};
