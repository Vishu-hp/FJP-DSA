class Solution {
public:
    TreeNode* first,*second,*prev;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
       inorder(root->left);
        
        if(first==NULL && prev->val > root->val){
            first = prev;
        }
        
        if(first!=NULL && prev->val > root->val){
            second = root;
        }
        
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = NULL;
        second=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        return;
    }
};
