#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}


int min(Node *node){
//     Write your code here
if(node==NULL){
  return -1;
}
  while(node->left != NULL){
    node= node->left;
  }
  return node->data;
}

int max(Node *node){
//     Write your code here
if(node==NULL){
  return -1;
}
while(node->right != NULL){
    node= node->right;
  }
  return node->data;
}

int sum(Node * node){
    
//     Write your code here
  if(node==NULL){
    return 0;
  }

  int lSum = sum(node->left);
  int rSum = sum(node->right);
  return lSum+rSum+node->data;
}


int size(Node * node){
    
//     Write your code here
if(node==NULL){
    return 0;
  }

  int lSize = size(node->left);
  int rSize = size(node->right);
  return lSize+rSize+1;
}


bool find(Node * node, int data){
    
//     Write your code here
  if(node==NULL){
    return false;
  }


// RECURSIVE
  // if(node->data == data){
  //   return true;
  // }

  // bool ans;
  // if(node->data < data){
  //   ans = find(node->right,data);
  // }
  // else if(node->data >data){
  //   ans = find(node->left,data);
  // }
  // return ans;


// ITERATIVE

  Node *curr = node;
  while(true){
    if(curr==NULL){
      return false;
    }

    if(data > curr->data){
      curr = curr->right;
    }
    else if(data < curr->data){
      curr = curr->left;
    }
    else{
      return true;
    }
  }
}



int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);
  cout << size(root) << "\n" << sum (root) << "\n" << max(root) << "\n" << min(root) <<  "\n";
  if (find(root, data)) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
}
