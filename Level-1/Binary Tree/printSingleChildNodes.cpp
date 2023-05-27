#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data,Node *left,Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

  int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++],nullptr,nullptr);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node) {
    if (node == nullptr) {
      return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout<<str<<endl;

    display(node->left);
    display(node->right);
}

//   void printSingleChildNodes(Node *node, Node *parent){
//     // write your code here
//     if(node==NULL){
//         return;
//     }
    
    
//     if(parent!=NULL && parent->left==NULL && parent->right==node){
//         cout<<node->data<<endl;
//     }
//     if(parent!=NULL && parent->right==NULL && parent->left==node){
//         cout<<node->data<<endl;
//     }

//     printSingleChildNodes(node->left,node);
//     printSingleChildNodes(node->right,node);
//   }


void printSingleChildNodes(Node *node){
    // write your code here
    if(node==NULL){
        return;
    }
    
    
    if(node->left==NULL && node->right!=NULL){
        cout<<node->right->data<<endl;
    }
    if(node->right==NULL && node->left!=NULL){
        cout<<node->left->data<<endl;
    }

    printSingleChildNodes(node->left);
    printSingleChildNodes(node->right);
  }

  int main()
    {
        vector<int> arr;
        int n;
        cin>>n;
        
        for(int i = 0; i<n; i++){
            string inp;
            cin>>inp;
            if(inp != "n"){
                arr.push_back(stoi(inp));
            }
            else{
                arr.push_back(-1);
            }
        }
        
    
        Node *root = constructTree(arr);
        // printSingleChildNodes(root, nullptr);
        printSingleChildNodes(root);
    }
