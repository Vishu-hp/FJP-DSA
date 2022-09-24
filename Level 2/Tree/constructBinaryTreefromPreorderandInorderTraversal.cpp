// LEETCODE 105
// ************************************************

class Solution {
public:
    TreeNode* solve(vector<int>&pre,int psi,int pei,vector<int>&in,int isi,int iei){
        if(isi>iei){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[psi]);
        int idx = isi;
        while(idx<=iei){
            if(in[idx] == pre[psi]){
                break;
            }
            idx++;
        }
        
        int numEl = idx-isi;
        
        root->left = solve(pre,psi+1,psi+numEl,in,isi,idx-1);
        root->right = solve(pre,psi+numEl+1,pei,in,idx+1,iei);    
    
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pSize = preorder.size();
        int iSize = inorder.size();
        
        return solve(preorder,0,pSize-1,inorder,0,iSize-1);
    }
};
