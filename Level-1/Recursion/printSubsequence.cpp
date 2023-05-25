#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    printSS(ques.substr(1),ans+ques.substr(0,1));
    printSS(ques.substr(1),ans);
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
