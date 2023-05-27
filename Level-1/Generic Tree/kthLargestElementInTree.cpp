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
            //t->data=arr[i];
            
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



void cnf(Node *node, int data){
    if(node->data > data)
    {
        if(node->data <c)
        {
            c = node->data;
        }
    }
    
    if(node->data < data)
    {
        if(node->data > flloor)
        {
            flloor = node->data;
        }
    }
    
    for(Node *child: node->children)
    {
        cnf(child,data);
    }
    
}

int f=INT_MIN;

void solve(Node* node,int val){
    if(node->data <val){
        if(node->data > f){
            f = node->data;
        }
    }

    for(Node* child:node->children){
        solve(child,val);
    }
}

int kthlarge(Node *node, int k)
{
    //Write your code here
    int val = INT_MAX;
    for(int i=0;i<k;i++){
        solve(node,val);
        val = f;
        f = INT_MIN;
    }
    return val;
}

int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    Node *root=construct(arr,n);
    int kthlrg = kthlarge(root,k);
    cout<<kthlrg;
}
