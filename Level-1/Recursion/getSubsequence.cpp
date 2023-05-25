#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.length()==0){
        vector<string>base;
        base.push_back("");
        return base;
    }
    
    char ch = s[0];
    string ros = s.substr(1);
    vector<string>rres = gss(ros);
    vector<string>ans;

    //exc
    for(string ss:rres){
        ans.push_back(ss);
    }

    //inc
    for(string ss:rres){
        ans.push_back(ch+ss);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << "]";
}
