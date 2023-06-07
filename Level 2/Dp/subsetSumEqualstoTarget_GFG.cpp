// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// RECURSION + MEMOIZATION
// class Solution{   
// public:
//     bool solve(vector<int>&arr,int sum, int idx, vector<vector<int>>&memo){
//         if(sum == 0 ){
//             return true;
//         }
        
//         if(idx<0){
//             return false; 
//         }
        
//         if(memo[idx][sum]!= -1){
//             return (memo[idx][sum]==1)?true:false;
//         }
        
//         bool a1 = false;
//         if(sum>=arr[idx]){
//             a1 = solve(arr, sum-arr[idx], idx-1, memo);
//         }
//         bool a2 = solve(arr, sum, idx-1, memo);
        
//         if(a1 || a2){
//             memo[idx][sum] = 1;
//         }
//         else{
//             memo[idx][sum]  = 0;
//         }
        
//         return a1||a2;
//     }

//     bool isSubsetSum(vector<int>&arr, int sum){
//         // code here 
//         vector<vector<int>>memo(arr.size(),vector<int>(sum+1,-1));
//         return solve(arr, sum, arr.size()-1,memo);
//     }
// };


// TABULATION
// class Solution{   
// public:
//     bool isSubsetSum(vector<int>&arr, int sum){
//         // code here
//         int n = arr.size();
//         vector<vector<bool>>tab(n,vector<bool>(sum+1,false));
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<sum+1;j++){
//                 if(j==0){
//                     tab[i][j] = true;
//                 }
//                 else if(i==0){
//                     if(arr[i] == j){
//                         tab[i][j] = true;
//                     }
//                     else{
//                         tab[i][j]=false;
//                     }
//                 }
//                 else{
//                     bool a1 = (j>=arr[i])?tab[i-1][j-arr[i]]:false;
//                     bool a2 = tab[i-1][j];
                    
//                     tab[i][j] = a1||a2;
//                 }
//             }
//         }
        
//         return tab[n-1][sum];
//     }
// };

// SPACE OPTIMIZATION
class Solution{   
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        // code here
        int n = arr.size();
        vector<int>prev(sum+1,0), curr(sum+1,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0){
                    curr[j] = true;
                }
                else if(i==0){
                    if(arr[i] == j){
                        curr[j] = true;
                    }
                    else{
                        curr[j]=false;
                    }
                }
                else{
                    bool a1 = (j>=arr[i])?prev[j-arr[i]]:false;
                    bool a2 = prev[j];
                    
                    curr[j] = a1||a2;
                }
            }
            prev = curr;
        }
        
        return prev[sum];;
    }
};
