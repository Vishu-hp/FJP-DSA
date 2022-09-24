// LEETCODE 106
// *******************************************************

class Solution {
public:
    TreeNode* solve(vector<int>&in,int isi,int iei,vector<int>&post,int psi,int pei){
        if(isi>iei){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(post[pei]);
        int idx = isi;
        while(in[idx]!= post[pei]){
            idx++;
        }
        int num = idx-isi;
        root->left = solve(in,isi,idx-1,post,psi,psi+num-1);
        root->right = solve(in,idx+1,iei,post,psi+num,pei-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size();
        int n = postorder.size();
        
        return solve(inorder,0,m-1,postorder,0,n-1);
    }
};
