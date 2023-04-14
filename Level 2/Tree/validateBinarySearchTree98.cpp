class Solution {
public:
    long  prev=-1e14;

    bool isValidBST(TreeNode *root)
    {
        if(root==NULL){
            return true;
        }

        if(!isValidBST(root->left)){
            return false;
        }

        if(prev >= root->val){
            return false;
        }

        prev=root->val;

        if(!isValidBST(root->right)){
            return false;
        }
        return true;
    }
};
