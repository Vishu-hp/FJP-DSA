#include <bits/stdc++.h>
using namespace std;

vector<string> greyCode(int n){
    if(n==0){
        vector<string>ans;
        ans.push_back("0");
        return ans;
    }

    if(n==1){
        vector<string>ans;
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }

    vector<string>ta = greyCode(n-1);
    vector<string>ans;

    for(auto x:ta){
        ans.push_back("0"+x);
    }

    for(int i=ta.size()-1;i>=0;i--){
        ans.push_back("1"+ta[i]);
    }
    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<string>gc = greyCode(n);
    vector<int>ans;
    
    for(auto s:gc){
        ans.push_back(stoi(s,0,2));
    }

    cout<<"[ ";
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<", ";
    }
    cout<<ans[ans.size()-1]<<" ]";

    return 0;
}
