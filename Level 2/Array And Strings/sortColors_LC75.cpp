class Solution {
public:
    void swap(vector<int>&nums,int a,int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;

        return;    
    }

    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int low=0, mid=0, high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums,low,mid);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums,mid,high);
                high--;
            }
        }   
        return;
    }
};
