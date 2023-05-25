#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    //Write your code here
    if(sr>dr || sc>dc){
        vector<string>ans;
        return ans;
    }

    if(sr==dr && sc==dc){
        vector<string>ans;
        ans.push_back("");
        return ans;
    }

    vector<string>ans;
    for(int i=1;i<= dc-sc;i++){
        vector<string>ip = get_maze_paths(sr,sc+i,dr,dc);
        for(string ss:ip){
            ans.push_back("h"+to_string(i)+ss);
        }
    }
    for(int i=1;i<= dr-sr;i++){
        vector<string>ip = get_maze_paths(sr+i,sc,dr,dc);
        for(string ss:ip){
            ans.push_back("v"+to_string(i)+ss);
        }
    }

    for(int i=1;i<= min(dc-sc,dr-sr);i++){
        vector<string>ip = get_maze_paths(sr+i,sc+i,dr,dc);
        for(string ss:ip){
            ans.push_back("d"+to_string(i)+ss);
        }
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
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
