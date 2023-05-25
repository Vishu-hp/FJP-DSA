#include<bits/stdc++.h>
using namespace std;


    vector<string> printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        if(sr==dr && sc==dc){
            vector<string>tmpAns;
            tmpAns.push_back("");
            return tmpAns;
        }

        if(sr>dr || sc>dc){
            vector<string>tmpAns;
            return tmpAns;
        }
        vector<string>ans;
        for(int jump=1;jump<=dc-sc;jump++){
            vector<string>subAns = printMazePaths(sr,sc+jump,dr,dc,psf);
            for(string s:subAns){
                ans.push_back("h"+to_string(jump)+s);
            }
        }
        for(int jump=1;jump<=dr-sr;jump++){
            vector<string>subAns = printMazePaths(sr+jump,sc,dr,dc,psf);
            for(string s:subAns){
                ans.push_back("v"+to_string(jump)+s);
            }
        }
        for(int jump=1;jump<=min(dr-sr,dc-sc);jump++){
            vector<string>subAns = printMazePaths(sr+jump,sc+jump,dr,dc,psf);
            for(string s:subAns){
                ans.push_back("d"+to_string(jump)+s);
            }
        }
        return ans;
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        vector<string>ans = printMazePaths(0, 0, n - 1, m - 1, "");
        for(string s:ans){
            cout<<s<<endl;
        }
    }
