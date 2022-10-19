// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxS=INT_MIN;
    
    
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int  l = solve(root->left);
        int r = solve(root->right);
        
        int ans;
        maxS = max(maxS,l+r+root->val);
        ans = max(0,max(l,r)+root->val);
        return ans;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        int tmp = solve(root);
        return maxS;
    }
};
