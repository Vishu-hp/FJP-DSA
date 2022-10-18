#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&par,int mem){
    if(par[mem] == mem){
        return mem;
    }
    
    return find(par,par[mem]);
}

void union_(vector<int>&par,int x,int y){
    int xl = find(par,x);
    int yl = find(par,y);
    
    if(xl!=yl){
        par[xl] = yl;
    }
}

int main(){
    vector<int>par(11);
    for(int i=0;i<11;i++){
        par[i]=i;
    }
    int n=8;
    vector<vector<int>>edges(8,vector<int>(2));
    for(int i=0;i<8;i++){
        int a,b;
        cin>>a>>b;
        edges[i][0]= a;
        edges[i][1] = b;
        union_(par,a,b);
    }
    
    int a=1,b=8;
    if(find(par,a)==find(par,b)){
        cout<<"Connected"<<endl;
    }
    else{
        cout<<"Disconnected"<<endl;
    }
    
   
    
    
    return 0;
}
