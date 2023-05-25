#include <bits/stdc++.h>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }

    int n=str.length();
    for(int i=0;i<n;i++){
        char ch=str[i];
        printPermutations(str.substr(0,i)+str.substr(i+1),asf+ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
