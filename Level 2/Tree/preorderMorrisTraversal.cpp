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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* tmp1 = root->left;
                while(tmp1->right!=NULL && tmp1->right!=root){
                    tmp1 = tmp1->right;
                }
                
                if(tmp1->right==NULL){
                    ans.push_back(root->val);
                    tmp1->right = root;
                    root= root->left;
                }
                else if(tmp1->right==root){
                    tmp1->right=NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};
