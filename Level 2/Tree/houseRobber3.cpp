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
class Pair{
    public:
    int rob;
    int leave;
    
    Pair(){}
    
    Pair(int rob,int leave){
        this->rob = rob;
        this->leave = leave;
    }
};

Pair solve(TreeNode* root){
    if(root==NULL){
        Pair tmp;
        tmp.rob = 0;
        tmp.leave =0;
        return tmp;
    }
    
    Pair leftAns = solve(root->left);
    Pair rightAns = solve(root->right);
    Pair ans;
    ans.rob = root->val + leftAns.leave +rightAns.leave;
    ans.leave = max(leftAns.rob,leftAns.leave)+max(rightAns.rob,rightAns.leave);
    return ans;
}

class Solution {
public:
    int rob(TreeNode* root) {
        Pair ans = solve(root);
        // cout<<ans.rob<<" "<<ans.leave<<endl;
        return max(ans.rob,ans.leave);
    }
};
