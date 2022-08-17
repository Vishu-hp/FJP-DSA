#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>> n;
   //Write your code here
   unordered_map<string,string>inp;
   string src,des;
   for(int i=0;i<n;i++){
    cin>>src>>des;
    inp[src]=des;
   }

    unordered_map<string,bool>startPoint;
    for(auto x:inp){
        string src = x.first;
        string des = x.second;

        startPoint[des]=false;
        if(startPoint.count(src)==0){
            startPoint[src]=true;
        }
    }

    string start;
    for(auto x:startPoint){
        if(x.second == true){
            start = x.first;
            break;
        }
    }

    while(inp.count(start)>0){
        cout<<start<<" -> ";
        start = inp[start];
    }
    cout<<start<<"."<<endl;
}
