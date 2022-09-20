class Pair{
    public:
    int l;
    Node* node;
    
    Pair(Node* node,int l){
        this->node = node;
        this->l = l;
    }
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int,int>ump;
        int minL=INT_MAX;
        int maxL = INT_MIN;
        queue<Pair>main;
        queue<Pair>helper;
        main.push(Pair(root,0));
        while(main.size()>0){
            int n = main.size();
            for(int i=1;i<=n;i++){
                Pair rem = main.front();
                main.pop();
                
                if(ump.count(rem.l)==0){
                    ump[rem.l] = rem.node->data;
                }
                
                minL = min(minL,rem.l);
                maxL = max(maxL,rem.l);
                
                if(rem.node->left){
                    helper.push(Pair(rem.node->left,rem.l-1));
                }
                
                if(rem.node->right){
                    helper.push(Pair(rem.node->right,rem.l+1));
                }
                
                if(main.size()==0){
                    queue<Pair>tmp = main;
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
