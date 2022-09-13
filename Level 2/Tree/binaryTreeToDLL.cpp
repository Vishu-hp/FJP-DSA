// METHOD -1 RECURSION
// ****************************************************

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==NULL){
            return NULL;
        }
        
        Node* leftAns = bToDLL(root->left);
        Node* rightAns = bToDLL(root->right);
        
        while(leftAns!=NULL && leftAns->right!=NULL){
            leftAns = leftAns->right;
        }
        
        while(rightAns!=NULL && rightAns->left!=NULL){
            rightAns = rightAns->left;
        }
        
        
        if(leftAns==NULL){
            root->left=NULL;
        }
        else{
            leftAns->right = root;
            root->left = leftAns;
        }
        
        if(rightAns==NULL){
            root->right=NULL;
        }
        else{
            rightAns->left = root;
            root->right = rightAns;
        }
        
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
};
