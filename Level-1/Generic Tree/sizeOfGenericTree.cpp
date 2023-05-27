#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    vector<Node*>children;

    Node(int data){
        this->data=data;
    }
};

Node *newNode(int key){
	Node *temp=new Node(key);
	// temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    // Node *root=NULL;
    // stack<Node*>st;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==-1){
    //         st.pop();
    //     }else{
    //         Node *t=newNode(arr[i]);
    //         if(st.size()>0){
    //             st.top()->children.push_back(t);
    //         }else{
    //             root=t;
    //         }
    //         st.push(t);
    //     }
    // }
    // return root;


    Node* root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(i==0){
            Node *newNode = new Node(arr[0]);
            root=newNode;
            st.push(newNode);
        }
        else{
            if(arr[i]==-1){
                st.pop();
            }
            else{
                Node* newNode = new Node(arr[i]);
                Node* par = st.top();
                par->children.push_back(newNode);
                st.push(newNode);
            }
        }
    }
    return root;
}
void display(Node *node)
{
    cout<<node->data<<" -> ";
    for(Node* child:node->children){
        cout<<child->data<<" ";
    }
    cout<<endl;

    for(Node* child:node->children){
        display(child);
    }
}

int size(Node *node){
  //write your code here
    int ans=0;
    for(Node* child:node->children){
        ans += size(child);
    }
    ans= ans+1;
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    int sz=size(root);
    cout<<sz<<endl;
//    display(root);
}
