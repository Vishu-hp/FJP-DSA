class Pair{
    public:
    TreeNode* node;
    int l;
    
    Pair(TreeNode* node,int l){
        this->node = node;
        this->l = l;
    }
};

bool operator < (const Pair &p1 , const Pair &p2){
    return p1.node->val > p2.node->val;
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int,vector<int>>ump;
        int minL=INT_MAX , maxL = INT_MIN;
        priority_queue<Pair>main;
        priority_queue<Pair>helper;
        main.push(Pair(root,0));

        while(main.size()>0){
            int n = main.size();
            for(int i=1;i<=n;i++){
                Pair rem = main.top();
                main.pop();
                
                ump[rem.l].push_back(rem.node->val);
                
                minL = min(minL,rem.l);
                maxL = max(maxL,rem.l);
                
                if(rem.node->left){
                    helper.push(Pair(rem.node->left,rem.l-1));
                }
                if(rem.node->right){
                    helper.push(Pair(rem.node->right,rem.l+1));
                }
                
                if(main.size()==0){
                    priority_queue<Pair>tmp = main;
                    main = helper;
                    helper = tmp;
                }
            }
        }
        while(minL<=maxL){
                ans.push_back(ump[minL]);
                minL++;
        }
        return ans;
    }
};
