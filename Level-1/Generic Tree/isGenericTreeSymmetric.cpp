#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int c= INT_MAX;
int flloor= INT_MIN;

struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
            
            
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}

bool isMirror(Node* node1,Node* node2){
    if(node1->children.size()!=node2->children.size()){
        return false;
    }

    for(int i=0;i<node1->children.size();i++){
        Node* child1 = node1->children[i];
        Node* child2 = node2->children[node2->children.size()-1-i];
        if(isMirror(child1,child2) == false){
            return false;
        }
    }
    return true;
}

bool issym(Node *node)
{
    //Write your code here
    return isMirror(node,node);
}



int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    bool sym = issym(root);
    if(sym == 1){
    cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
