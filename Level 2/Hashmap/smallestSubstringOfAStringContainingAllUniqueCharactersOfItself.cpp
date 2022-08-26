#include <bits/stdc++.h>
using namespace std;

int solution(string str){
  // write your code here
  int n= str.length();
  int ans=INT_MAX;
  unordered_set<char>ust;
  for(int i=0;i<n;i++){
	  ust.insert(str[i]);
  }
  
	unordered_map<char,int>freq;
  int i=0,j=0;
  while(j<n){
	  freq[str[j]]++;
	  if(freq.size()==ust.size()){
		  ans = min(ans,j-i+1);
	  }
	  while(freq.size()==ust.size()){
		  ans = min(ans,j-i+1);
		  freq[str[i]]--;
		  if(freq[str[i]]==0){
			  freq.erase(str[i]);
		  }
		  i++;
	  }
	  j++;
  }

  return ans;
}

int main(){
	string str;
	cin>>str;
	cout <<solution(str);
}
