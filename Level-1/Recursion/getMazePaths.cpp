#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
// vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
//     if(sr==dr && sc==dc){
//         vector<string>base;
//         base.push_back("");
//         return base;
//     }

//     vector<string>ans;
//     if(sc+1<=dc){
//         vector<string>s1 = getMazePaths(sr,sc+1,dr,dc);
//         for(string s:s1){
//             ans.push_back("h"+s);
//         }
//     }
//     if(sr+1<=dr){
//         vector<string>s2= getMazePaths(sr+1,sc,dr,dc);
//         for(string s:s2){
//             ans.push_back("v"+s);
//         }
//     }
//     return ans;
// }

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    	if(sr==dr && sc==dc){
		vector<string>tmpAns;
		tmpAns.push_back("");
		return tmpAns;
	}
	
	if(sr>dr || sc>dc){
		vector<string>tmpAns;
		return tmpAns;
	}
	vector<string>hStep = getMazePaths(sr,sc+1,dr,dc);
	vector<string>vStep = getMazePaths(sr+1,sc,dr,dc);
	
	vector<string>ans;	
	for(string s:hStep){
		string path = "h"+s;
		ans.push_back(path);
	}
	for(string s:vStep){
		string path = "v"+s;
		ans.push_back(path);
	}
	return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
