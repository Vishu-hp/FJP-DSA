// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1

class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        cpp_int ans=0;
        vector<cpp_int>arr(n+1,0);
        arr[0]=1;
        arr[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                arr[i] += (arr[j-1]*arr[i-j]);
            }
        }
        return arr[n];
    }
};
