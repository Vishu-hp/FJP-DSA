class Solution {
  public:
    vector<Node*> nodeToRootPath(Node* root,int target){
        if(root==NULL){
            vector<Node*>tmp;
            return tmp;
        }
        
        if(root->data==target){
            vector<Node*>tmp;
            tmp.push_back(root);
            return tmp;
        }
        
        vector<Node*>leftAns = nodeToRootPath(root->left,target);
        if(leftAns.size()>0){
            leftAns.push_back(root);
            return leftAns;
        }
        vector<Node*>rightAns = nodeToRootPath(root->right,target);
        if(rightAns.size()>0){
            rightAns.push_back(root);
            return rightAns;
        }
        return rightAns;
    }
    
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        vector<Node*>path = nodeToRootPath(root,target);
        if(path.size()==0){
            return 0;
        }
        int time=0;
        for(int i=0;i<path.size();i++){
            if(i==0){
                time = height(path[i])-1;
            }
            else{
                Node* block = path[i-1];
                if(path[i]->left == block){
                    time = max(time,height(path[i]->right)+i);
                }
                else if(path[i]->right == block){
                    time = max(time,height(path[i]->left)+i);
                }
            }
        }
        return time;
    }
};
