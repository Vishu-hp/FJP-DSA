// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        if(n==0){
            return 0;
        }
       int k=1;
       
       while(1){
           int mask = (1<<(k-1));
           
           int v = n & mask;
           if(v>0){
               return k;
           }
           k++;
       }
       
    }
};
