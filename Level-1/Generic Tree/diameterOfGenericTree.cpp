#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*>children;
};



Node* construct(vector<int>&arr) {
    Node* root = nullptr;

    stack <Node*> st;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == -1) {
        st.pop();
      } else {
        Node* t = new Node();
        t->data = arr[i];

        if (st.size() > 0) {
          st.top()->children.push_back(t);
        } else {
          root = t;
        }
        st.push(t);
      }
    }
    return root;
  }
int dia = 0;
 int diameter(Node* root){ 
//write your code here

  int lh = -1,slh=-1;
  for(Node* child:root->children){
    int ht = diameter(child);
    if(ht>lh){
      slh = lh;
      lh = ht;
    }
    else if(ht>slh){
      slh = ht;
    }
  }
  int tmpDia = lh + slh +2;
  dia = max(dia,tmpDia);
  return lh+1;
}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    dia=0;
    diameter(root);
    cout<<dia<<endl;
    
}
