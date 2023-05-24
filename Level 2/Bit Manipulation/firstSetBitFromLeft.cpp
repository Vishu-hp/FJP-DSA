// https://www.codingninjas.com/codestudio/library/find-the-leftmost-and-rightmost-set-bit-of-a-number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int pos=0;
    while(n>0){
        n = n>>1;
        pos++;
    }

    cout<<pos<<endl;

    return 0;
}
