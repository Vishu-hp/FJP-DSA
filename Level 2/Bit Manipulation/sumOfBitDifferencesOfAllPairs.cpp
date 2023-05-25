class Solution{
public:
    long long mod = 1e9+7;
    int countBits(int N, long long int A[])
    {
        // code here
        long long ans=0;
        for(int i=0;i<32;i++){
            long long s=0;        
            for(int j=0;j<N;j++){
                if(A[j]&(1<<i)){
                    s++;
                }
            }
            
            ans = (ans + (((s*(N-s))%mod)*2)%mod)%mod;
        }
        return ans;
    }
};
