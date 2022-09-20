class Pair{
    public:
  Node* node;
  int l;
  
  Pair(Node* node,int l){
      this->node = node;
      this->l = l;
  }
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int,int>ump;
        int minL = INT_MAX;
        int maxL = INT_MIN;
        queue<Pair>main;
        queue<Pair>helper;
        main.push(Pair(root,0));
        
        while(main.size()>0){
            Pair rem = main.front();
            main.pop();
            minL = min(minL,rem.l);
            maxL = max(maxL,rem.l);
            
            ump[rem.l] = rem.node->data;
            
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
        
        while(minL<=maxL){
            ans.push_back(ump[minL]);
            minL++;
        }
        return ans;
    }
};
