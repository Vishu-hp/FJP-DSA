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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* tmp = root->left;
                while(tmp->right!=NULL && tmp->right!=root){
                    tmp = tmp->right;
                }
                
                if(tmp->right==NULL){
                    tmp->right = root;
                    root = root->left;
                }
                else if(tmp->right==root){
                    ans.push_back(tmp->right->val);
                    tmp->right=NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};
