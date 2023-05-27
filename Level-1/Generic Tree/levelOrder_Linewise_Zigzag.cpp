#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node *> children;



  Node(int data)

  {

    this->data = data;

  }

};

Node *constructor01(vector<int> &arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node *> stack;

  stack.push_back(new Node(arr[0]));



  Node *root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node *node = stack.back();

      Node *nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}
void levelOderZigZag(Node *node)

{

  //write code here
  stack<Node*>curr;
  stack<Node*>next;
  curr.push(node);
  int l=0;
  while(curr.size()>0){
    Node* rem = curr.top();
    curr.pop();

    cout<<rem->data<<" ";
    if(l%2==0){
      for(Node* child:rem->children){
        next.push(child);
      }
    }
    else{
      for(int i=rem->children.size()-1;i>=0;i--){
        Node* child = rem->children[i];
        next.push(child);
      }
    }
    if(curr.size()==0){
      cout<<endl;
      stack<Node*>tmp = curr;
      curr=next;
      next=tmp;
      l++;
    }
  }
  return;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root=constructor01(arr);
    levelOderZigZag(root);
}

int main()
{
    solve();
    return 0;
}
