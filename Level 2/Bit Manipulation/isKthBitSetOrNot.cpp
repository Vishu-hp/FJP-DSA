// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        if(n & (1 << k)){
            return true;
        }
        else{
            return false;
          
        }
        
        
    }
};
