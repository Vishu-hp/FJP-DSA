class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int i=0;i<k;i++){
            freq[A[i]]++;
        }
        
        int i=k,j=0;
        while(i<n){
            ans.push_back(freq.size());
            freq[A[i]]++;
            freq[A[j]]--;
            if(freq[A[j]]==0){
                freq.erase(A[j]);
            }
            i++;
            j++;
        }
        ans.push_back(freq.size());
        return ans;
    }
};
