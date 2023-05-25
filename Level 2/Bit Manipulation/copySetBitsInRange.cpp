class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        long long mask=1;
        mask = mask<<(r-l+1);
        // mask = mask-1;
        mask--;
        mask = mask<<(l-1);
        
        mask = mask&y;
        x = x|mask;
        return x;
    }
};
