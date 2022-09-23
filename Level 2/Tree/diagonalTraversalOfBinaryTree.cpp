vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>ans;
   if(root==NULL){
       return ans;
   }
   if(root->left==NULL && root->right==NULL){
       ans.push_back(root->data);
       return ans;
   }
   
   queue<Node*>q;
   q.push(root);
   
   while(q.size()>0){
       int n=q.size();
       
       for(int i=1;i<=n;i++){
           Node* rem = q.front();
           q.pop();
           
           while(rem!=NULL){
               if(rem->left!=NULL){
                   q.push(rem->left);
               }
               ans.push_back(rem->data);
               rem = rem->right;
           }
       }
   }
   return ans;
}
