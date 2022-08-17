#include<bits/stdc++.h>
using namespace std;

int traverse(unordered_map<string,unordered_set<string>>&tree,string ceo,map<string,int>&empMap){
  int cnt=0;
  for(auto x:tree[ceo]){
    cnt += traverse(tree,x,empMap);
  }
  empMap[ceo] = cnt;
  return cnt+1;
}
 
int main()
{
   int n;
   cin>>n;
  
  //Write your code here
  unordered_map<string,unordered_set<string>>tree;
  string ceo;
  for(int i=0;i<n;i++){
    string a,b;
    cin>>a>>b;
    if(a==b){
      ceo = a;
    }
    else{
      tree[b].insert(a);
    }
  }
  

  map<string,int>empMap;
  traverse(tree,ceo,empMap);
  for(auto x:empMap){
    cout<<x.first<<" "<<x.second<<endl;
  }
return 0;
    
}
