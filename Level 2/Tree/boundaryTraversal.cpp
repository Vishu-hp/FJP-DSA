class Solution {
public:
    void traverseTree(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        
        traverseTree(root->left,ans);
        traverseTree(root->right,ans);
    }
    
    void leftBoundary(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL){
            ans.push_back(root->data);
            leftBoundary(root->left,ans);
        }
        else if(root->right!=NULL){
            ans.push_back(root->data);
            leftBoundary(root->right,ans);
        }
    }
    
    void rightBoundary(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        if(root->right!=NULL){
            rightBoundary(root->right,ans);
             ans.push_back(root->data);
        }
        else if(root->left!=NULL){
            rightBoundary(root->left,ans);
            ans.push_back(root->data);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            return ans;
        }
        leftBoundary(root->left,ans);
        traverseTree(root,ans);

        rightBoundary(root->right,ans);    
        
        
        return ans;
    }
};
