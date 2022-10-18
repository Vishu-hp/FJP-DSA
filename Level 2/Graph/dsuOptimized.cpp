#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&par,int mem){
    if(par[mem] == mem){
        return mem;
    }
    int gl = find(par,par[mem]);
    par[mem] = gl;
    
    return gl;
}

void union_(vector<int>&par,vector<int>&rank,int x,int y){
    int xl = find(par,x);
    int yl = find(par,y);
    
    if(xl!=yl){
        if(rank[xl]>rank[yl]){
            par[yl] = xl;
        }
        else if(rank[yl]>rank[xl]){
            par[xl]=yl;
        }
        else{
            par[xl] = yl;
            rank[yl]++;
        }
    }
}

int main(){
    vector<int>par(11);
    for(int i=0;i<11;i++){
        par[i]=i;
    }
    
    vector<int>rank(11,1);
    int n=8;
    vector<vector<int>>edges(10,vector<int>(2));
    for(int i=0;i<10;i++){
        int a,b;
        cin>>a>>b;
        edges[i][0]= a;
        edges[i][1] = b;
        union_(par,rank,a,b);
    }
    
    int a=1,b=6;
    if(find(par,a)==find(par,b)){
        cout<<"Connected"<<endl;
    }
    else{
        cout<<"Disconnected"<<endl;
    }
    
   
    
    
    return 0;
}
