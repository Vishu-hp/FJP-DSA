class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,unsigned int>ump;
        ump[root]=1;
        unsigned int ans=0;
        while(q.size()>0){
            int n =q.size();
            unsigned int start,end;
            for(int i=1;i<=n;i++){
                TreeNode* rem = q.front();
                q.pop();
                
                if(i==1){
                    start = ump[rem];
                }
                if(i==n){
                    end = ump[rem];
                }
                
                if(rem->left){
                    q.push(rem->left);
                    ump[rem->left] = 2*ump[rem];
                }
                if(rem->right){
                    q.push(rem->right);
                    ump[rem->right] = 2*ump[rem] + 1;
                }
            }
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};
