// GREAT DSU PROBLEM. SOME ADJUSTMENTS ARE THERE TO GET IT ACCEPTED.
// INTUTION: WE NEED TO CHECK PAIRS

class Solution {
public:
    vector<int>par;

    int find(int n){
        if(par[n]==n){
            return n;
        }

        int p = find(par[n]);
        par[n]=p;
        return p;
    }

    bool union_(int a,int b){
        int p1 = find(a);
        int p2 = find(b);

        if(p1==p2){
            return true;
        }

        par[p2]=p1;
        return false;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int>mp1;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                mp1[leftChild[i]]++;

                if(mp1[leftChild[i]] > 1){
                    return false;
                }
            }

            if(rightChild[i]!=-1){
                mp1[rightChild[i]]++;

                if(mp1[rightChild[i]] > 1){
                    return false;
                }
            }
        }


        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }   

        for(int i=0;i<n;i++){
            int l = leftChild[i];
            int r = rightChild[i];

            if(l!=-1){
                bool sa = union_(i,l);
                if(sa){
                    return false;
                }
            }

            if(r!=-1){
                bool sa = union_(i,r);
                if(sa){
                    return false;
                }
            }
        }

        int p = find(0);
        for(int i=1;i<n;i++){
            int tp = find(i);
            if(p!=tp){
                return false;
            }
        }
        
        return true;
    }
};
