#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v){
    //Write your code here.
    int n = v.size();

    for(int i=0;i<n;i++){
        if(v[i]==0){
            v[i]=-1;
        }
    }

    int sum=0;
    int count=0;
    unordered_map<int,int>freq;
    freq[0]=1;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(freq.count(sum)>0){
            count += freq[sum];
            freq[sum]++;
        }
        else{
            freq[sum]=1;
        }
    }
    return count;
}


int main(){
    int n;cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << solution(v) << endl;

}
