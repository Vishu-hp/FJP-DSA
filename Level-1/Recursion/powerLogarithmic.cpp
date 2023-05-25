#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n==0){
        return 1;
    }
    int xPowerBy2 = powerLogarithmic(x,n/2);
    int ans = xPowerBy2*xPowerBy2;
    if(n%2==1){
        ans = ans*x;
    }
    return ans;
}



int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}
