// https://leetcode.com/problems/russian-doll-envelopes/description/

// https://www.geeksforgeeks.org/maximum-number-of-envelopes-that-can-be-put-inside-other-bigger-envelopes/   (nlogn   way) *************

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
 
    if (N == 0)
        return N;
 
    // Sort the envelopes in increasing
    // order of width and decreasing order
    // of height is width is same
    sort(envelopes.begin(), envelopes.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0]
                    or (a[0] == b[0] and a[1] > b[1]);
        });
 
    // To store the longest increasing
    // sequence of height
    vector<int> dp;
 
    // Finding LIS of the heights
    // of the envelopes
    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(dp.begin(),
                                dp.end(),
                                envelopes[i][1]);
 
        if (iter == dp.end())
            dp.push_back(envelopes[i][1]);
        else if (envelopes[i][1] < *iter)
            *iter = envelopes[i][1];
    }
 
    // Return the result
    return dp.size();
    }
};
