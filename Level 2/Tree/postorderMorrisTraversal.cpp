/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>revPreorder;
        
        while(root!=NULL){
            if(root->right==NULL){
                revPreorder.push_back(root->val);
                root = root->left;
            }
            else{
                TreeNode* tmp = root->right;
                while(tmp->left!=NULL && tmp->left!=root){
                    tmp = tmp->left;
                }
                
                if(tmp->left==NULL){
                    revPreorder.push_back(root->val);
                    tmp->left=root;
                    root = root->right;
                }
                else if(tmp->left==root){
                    tmp->left= NULL;
                    root = root->left;
                }
            }
        }
        
        reverse(revPreorder.begin(),revPreorder.end());
        return revPreorder;
    }
};
