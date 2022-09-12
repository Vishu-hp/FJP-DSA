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
    int cameras=0;
    int solve(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int leftState = solve(root->left);
        int rightState = solve(root->right);
        
        if(leftState==-1 || rightState==-1){
            cameras++;
            return 0;
        }
        
        if(leftState ==0 || rightState==0){
            return 1;
        }
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int ret = solve(root);
        if(ret==-1){
            cameras++;
        }
        return cameras;
    }
};
