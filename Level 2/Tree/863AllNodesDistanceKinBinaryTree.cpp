/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodeToRootPath(TreeNode* root,TreeNode* target){
        if(root==NULL){
            vector<TreeNode*>tmp;
            return tmp;
        }
        
        if(root==target){
            vector<TreeNode*>subAns;
            subAns.push_back(root);
            return subAns;
        }
        
        // vector<TreeNode*>ans;
        vector<TreeNode*>leftAns = nodeToRootPath(root->left,target);
        if(leftAns.size()>0){
            leftAns.push_back(root);
            return leftAns;
        }
        
         vector<TreeNode*>rightAns = nodeToRootPath(root->right,target);
        if(rightAns.size()>0){
            rightAns.push_back(root);
            return rightAns;
        }
        return rightAns;
    }
    
    void printKLevelDown(TreeNode* node,int k,TreeNode* block,vector<int>&ans){
        if(node==NULL || node==block){
            return;
        }
        
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        
        printKLevelDown(node->left,k-1,block,ans);
        printKLevelDown(node->right,k-1,block,ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*>path = nodeToRootPath(root,target);
        
        vector<int>ans;
        for(int i=0;i<path.size();i++){
            printKLevelDown(path[i],k-i,(i>0)?path[i-1]:NULL,ans);
        }
        return ans;
    }
};
