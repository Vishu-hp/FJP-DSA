// GREAT PROBLEM. SOLVED IT BY RECURSION. WE NEED CHECK LARGEST SUBSET THAT FOLLOWS GIVEN CONDITION.USED RECURSION + BACKTRACKING.
// AS WE WANT COMBINATION OF VALUES IN GIVEN ARRAY, WE CAN USE BITMASKING AND CONSTRAINTS ALLOWS IT.

class Solution {
public:
    // RECURSION AND BACKTRACKING
    // int solve(vector<vector<int>>& requests,int idx,vector<int>&change){
    //     if(idx == requests.size()){
    //         for(int i=0;i<change.size();i++){
    //             if(change[i]!=0){
    //                 return INT_MIN;
    //             }
    //         }
    //         return 0;
    //     }

    //     int u = requests[idx][0];
    //     int v = requests[idx][1];
    //     change[u] -= 1;
    //     change[v] += 1;
    //     int a1 = solve(requests,idx+1,change);
    //     if(a1!=INT_MIN){
    //         a1 += 1;
    //     }

    //     change[u] += 1;
    //     change[v] -= 1;
    //     int a2 = solve(requests,idx+1,change);
    //     return max(a1,a2);
    // }

    // int maximumRequests(int n, vector<vector<int>>& requests) {
    //   vector<int>change(n,0);
    //   return solve(requests,0,change);  
    // }

    // BITMASKING
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=0;
        int r = requests.size();
        for(int m = 0;m<(1<<r);m++){
            int bc = __builtin_popcount(m);
            vector<int>change(n,0);
            if(bc<=ans){
                continue;
            }

            int tmp = m;
            int idx=0;
            while(tmp>0){
                int lb = 1&tmp;
                if(lb){
                    change[requests[idx][0]] -=1;
                    change[requests[idx][1]] +=1;
                }
                tmp = tmp>>1;
                idx++;
            }

            bool flag=true;
            for(int i=0;i<n;i++){
                if(change[i]!=0){
                    flag=false;
                    break;
                }
            }

            if(flag){
                ans = bc;
            }
        }
        return ans;
    }
};
