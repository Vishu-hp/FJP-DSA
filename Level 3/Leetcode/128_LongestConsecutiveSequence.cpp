// GOOD HASHMAP IMPLEMENTATION PROBLEM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>ump;
        for(int x:nums){
            ump[x]=true;
        }

        for(int x:nums){
            if(ump.find(x-1)!=ump.end()){
                ump[x]=false;
            }
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]]){
                int l=1;
                int sp=nums[i];
                while(ump.find(sp+l) != ump.end()){
                    l++;
                }

                ans = max(ans,l);
            }
        }
        return ans;
    }
};

// SOLVED USING DSU
class Solution {
public:
    vector<int>par;
    vector<int>rank;

    int findPar(int n){
        if(par[n] == n){
            return n;
        }

        int p = findPar(par[n]);
        par[n] = p;
        return p;
    }

    void union_(int a,int b){
        int p1 = findPar(a);
        int p2 = findPar(b);

        if(p1==p2){
            return;
        }

        if(rank[p1]>rank[p2]){
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else{
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        par.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 1;    
        }

        unordered_map<int,int>ump;

        for(int i=0;i<n;i++){
            int num = nums[i];

            if(ump.find(num)!=ump.end()){
                continue;
            }

            ump[num] = i;

            if(ump.find(num+1) != ump.end()){
                union_(i,ump[num+1]);
            }

            if(ump.find(num-1) != ump.end()){
                union_(i,ump[num-1]);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans =max(ans,rank[i]);
        }
        return ans;
    }
};
