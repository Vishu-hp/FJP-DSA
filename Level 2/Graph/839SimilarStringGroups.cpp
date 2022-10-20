// https://leetcode.com/problems/similar-string-groups/

class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>ranker;
        
        int groups;
        
        vector<string>strs;
        DSU(vector<string>&strs){
            this->strs = strs;
            
            groups = strs.size();
            
            parent.resize(strs.size());
            ranker.resize(strs.size());
            
            for(int i=0;i<strs.size();i++){
                parent[i] = i;
                ranker[i] = 1;
            }
        }
        
        
        
        int find(int u){
            if(parent[u] ==u ){
                return u;
            }
            int gl = find(parent[u]);
            parent[u] = gl;
            return gl;
        }
        
        void union_(int idx1,int idx2){
            int l1 = find(idx1);
            int l2 = find(idx2);
            
            if(l1!=l2 && isSimilar(idx1,idx2)){
                if(ranker[l1]>ranker[l2]){
                    parent[l2] = l1;
                }
                else if(ranker[l2]>ranker[l1]){
                    parent[l1]=l2;
                }
                else{
                    parent[l1]=l2;
                    ranker[l2]++;
                }
                
                groups--;
            }
        }
        
        bool isSimilar(int idx1,int idx2){
            string s1= strs[idx1];
            string s2 = strs[idx2];
            int cnt=0;
            for(int i=0;i<s1.length();i++){
                if(s1[i]!=s2[i]){
                    cnt++;
                    
                    if(cnt>2){
                        return false;
                    }
                }
            }
            return true;
        }
    };
    
    int numSimilarGroups(vector<string>& strs) {
        DSU obj(strs);
        for(int i=0;i<strs.size()-1;i++){
            for(int j=i+1;j<strs.size();j++){
                obj.union_(i,j);
            }
        }
        return obj.groups;
    }
};
