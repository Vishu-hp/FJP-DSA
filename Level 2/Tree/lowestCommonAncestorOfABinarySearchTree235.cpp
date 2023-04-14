// Method -1

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if(root->val >p->val && root->val >q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};


// **************************************************************************************

// Method 2

class Solution {
public:
   vector<TreeNode*> nodeToRootPath(TreeNode* root,TreeNode *t){
        if(root->val == t->val){
            vector<TreeNode*>subAns;
            subAns.push_back(root);
            return subAns;
        }
        
        if(root->left!=NULL){
            vector<TreeNode*>subAns = nodeToRootPath(root->left,t);
            if(subAns.size()>0){
                subAns.push_back(root);
                return subAns;
            }
        }
        
        if(root->right!=NULL){
            vector<TreeNode*>subAns = nodeToRootPath(root->right,t);
            if(subAns.size()>0){
                subAns.push_back(root);
                return subAns;
            }
        }
        
        vector<TreeNode*>ans;
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ntrp1 = nodeToRootPath(root,p);
        vector<TreeNode*>ntrp2 = nodeToRootPath(root,q);
        
        int i=ntrp1.size()-1 , j = ntrp2.size()-1;
        while(i>=0 && j>=0 && ntrp1[i]==ntrp2[j]){
            i--;
            j--;
        }
        return ntrp1[i+1];
    }
};
