// https://leetcode.com/problems/longest-univalue-path/

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
    class Pair{
      public:
        int val;
        int ht;

        Pair(){}

        Pair(int val,int ht){
            this->val = val;
            this->ht = ht;
        }
    };
    
   int maxH=0;
    
    
    Pair solve(TreeNode* root){
        if(root==NULL){
            Pair p;
            p.val = INT_MIN;
            p.ht=0;
            return p;
        }
        
        Pair  l = solve(root->left);
        Pair r = solve(root->right);
        Pair ans;
        ans.ht = 1;
        ans.val = root->val;
        
        if(ans.val == l.val && ans.val == r.val){
            maxH = max(maxH,l.ht+r.ht+1);
            ans.ht = max(l.ht,r.ht)+1;
        }
        else if(ans.val != l.val && ans.val != r.val){
            maxH=max(maxH,max(l.ht,max(r.ht,1)));
        }
        else if(ans.val == l.val){
            maxH = max(maxH,max(l.ht+1,r.ht));
            ans.ht = l.ht+1;
        }
        else{
            maxH = max(maxH,max(r.ht+1,l.ht));
            ans.ht = r.ht+1;
        }
        
        return ans;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        Pair sol = solve(root);
        return maxH-1;
    }
};
