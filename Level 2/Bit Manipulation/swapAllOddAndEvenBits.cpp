class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	int oddmask = 0x55555555;
    	int evenmask = 0xAAAAAAAA;
    	int oddbits = n&oddmask;
    	int evenbits = n&evenmask;
    	
    	oddbits = oddbits<<1;
    	evenbits = evenbits>>1;
    	
    	int ans = oddbits | evenbits;
    	return ans;
    }
};
