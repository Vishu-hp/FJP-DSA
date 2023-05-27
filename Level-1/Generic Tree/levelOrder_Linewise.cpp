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

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

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

Node *linearize(Node *node)
{
//   write code here

// APPROACH 1
  // queue<Node*>q;
  // q.push(node);
  // while(q.size()>0){
  //   int n = q.size();
  //   for(int i=0;i<n;i++){
  //     Node* rem = q.front();
  //     q.pop();

  //     cout<<rem->data<<" ";

  //     for(Node* child:rem->children){
  //       q.push(child);
  //     }
  //   }
  //   cout<<endl;
  // }
  // return node;

// ********************************************
// APPROACH 2

  queue<Node*>currLevel;
  queue<Node*>nextLevel;
  currLevel.push(node);
  while(currLevel.size()>0){
    Node* rem = currLevel.front();
    currLevel.pop();

    cout<<rem->data<<" ";
    for(Node* child:rem->children){
      nextLevel.push(child);
    }

    if(currLevel.size()==0){
      cout<<endl;
      queue<Node*>tmp = currLevel;
      currLevel=nextLevel;
      nextLevel = tmp;
    }
  }
  return node;
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
    
  linearize(root);
  //  display(root);
    
}

int main()
{
    solve();
    return 0;
}
