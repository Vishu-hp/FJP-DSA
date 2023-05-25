#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<string> get_stair_paths(int n){
    //Write your code here
    	if(n==0){
		vector<string>subPath;
		subPath.push_back("");
		return subPath;
	}
	if(n<0){
		vector<string>subPath;
		return subPath;
	}
	vector<string>oneStep = get_stair_paths(n-1);
	vector<string>twoSteps = get_stair_paths(n-2);
	vector<string>threeSteps = get_stair_paths(n-3);

	vector<string>ans;
	for(string x:oneStep){
		string path = "1"+x;
		ans.push_back(path);
	}
	for(string x:twoSteps){
		string path = "2"+x;
		ans.push_back(path);
	}
	for(string x:threeSteps){
		string path = "3"+x;
		ans.push_back(path);
	}
	
	return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
