// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> levelOrder(Node* root){
        vector<vector<Node*>>ans;
        
        queue<Node*>q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            vector<Node*>tmp;
            for(int i=0;i<n;i++){
                Node* rem = q.front();
                q.pop();
                
                tmp.push_back(rem);
                
                if(rem->left){
                    q.push(rem->left);
                }
                
                if(rem->right){
                    q.push(rem->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        if(root->left==NULL && root->right==NULL){
            root->next=NULL;
            return root;
        }
        vector<vector<Node*>>lOT = levelOrder(root);
        
        for(vector<Node*>x:lOT){
            for(int i = x.size()-1;i>=0;i--){
                if(i==x.size()-1){
                    Node* tmp =x[i];
                    tmp->next=NULL;
                }
                else{
                    Node* tmp = x[i];
                    tmp->next = x[i+1];
                }
            }
        }
        return root;
    }
};
