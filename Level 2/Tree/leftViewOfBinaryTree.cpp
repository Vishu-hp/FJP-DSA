vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(root==NULL){
       return ans;
   }
   queue<Node*>q;
   q.push(root);
   
   while(q.size()>0){
       int n = q.size();
       for(int i=1;i<=n;i++){
           Node* rem = q.front();
           q.pop();
           
           if(i==1){
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
