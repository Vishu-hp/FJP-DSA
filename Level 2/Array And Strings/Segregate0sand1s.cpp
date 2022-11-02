// https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{   
public:
    void segregate0and1(int A[], int n) {
        // code here
         int l=0, r = n-1;
    while(l<r){
        while(l<r && A[l]==0){
            l++;
        }
        
        while(l<r && A[r]==1){
            r--;
        }
        
        if(l<r){
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
            l++;
            r--;
        }
    }
    return;
    }
};
