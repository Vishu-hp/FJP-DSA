#include<bits/stdc++.h>
using namespace std;

void solve(string s, string asf,int cnt,int idx){
    if(idx==s.length()){
        if(cnt!=0){
            asf += to_string(cnt);
        }
        cout<<asf<<endl;
        return;
    }
    
    string nasf = asf;
    if(cnt!=0){
        nasf += to_string(cnt);
    }
    nasf += s[idx];
    solve(s,nasf,0,idx+1);
    solve(s,asf,cnt+1,idx+1);
}

int main(){
    string s;
    cin>>s;
    
    solve(s,"",0,0);
    return 0;
}
