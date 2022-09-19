class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       
       vector<int>ans;
       if(root==NULL){
           return ans;
       }
       queue<Node*>q;
       q.push(root);
       
       while(q.size()>0){
           int n = q.size();
           for(int i=1;i<=n;i++){
               Node* rem= q.front();
               q.pop();
               
               if(i == n){
                   ans.push_back(rem->data);
               }
               
               if(rem->left){
                   q.push(rem->left);
               }
               
               
               if(rem->right){
                   q.push(rem->right);
               }
           }
       }
       return ans;
    }
};
