class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int xr=0;
        for(auto x: arr){
            xr = xr^x;
        }
        for(int i=1;i<=n;i++){
            xr = xr^i;
        }
        
        int rsb = xr&(~xr + 1);
        
        int a1=0,a2=0;
        for(auto x: arr){
            if(x&rsb){
                a1 = a1^x;
            }
            else{
                a2 = a2^x;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(i&rsb){
                a1 = a1^i;
            }
            else{
                a2 = a2^i;
            }
        }
        
        bool flag=false;
        for(auto x: arr){
            if(x==a1){
                flag=true;
                break;
            }
        }
        
        vector<int>ans;
        if(flag){
            ans.push_back(a1);
            ans.push_back(a2);
        }
        else{
            ans.push_back(a2);
            ans.push_back(a1);
        }
        return ans;
    }
};
