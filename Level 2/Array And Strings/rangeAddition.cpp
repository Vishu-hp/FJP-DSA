// https://nados.io/question/range-addition?zen=true

#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int s,e,v;

    Pair(){}

    Pair(int s,int e,int v){
        this->s=s;
        this->e=e;
        this->v=v;
    }
};

int main(){
    int n,k;
    cin>>n>>k;

    vector<Pair>q(k);
    for(int i=0;i<k;i++){
        cin>>q[i].s>>q[i].e>>q[i].v;
    }

    vector<int>ans(n+1,0);
    for(int i=0;i<k;i++){
        int s = q[i].s;
        int e = q[i].e;
        int v = q[i].v;

        ans[s] += v;
        ans[e+1] -= v; 
    }


    int pSum=0;
    for(int i=0;i<n+1;i++){
        pSum += ans[i];
        ans[i] = pSum;
    }

    ans.resize(n);

    for(int i=0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    cout<<endl;
    return 0;
}
