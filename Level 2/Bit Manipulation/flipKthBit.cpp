int flipKthBit(int n, int k)
    {
        // Your code here
        
        int mask = (1<<k);
        int ans = n^mask;
        return ans;
    }
