#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    // write your code here
    // if(idx<0){
    //     return -1;
    // }
    // int faith = lastIndex(arr,idx-1,x,n);
    // if(arr[idx]==x){
    //     return idx;
    // }
    // return faith;

    if(idx==n){
        return -1;
    }
    int recRes = lastIndex(arr,idx+1,x,n);
    if(recRes != -1){
        return recRes;
    }
    if(arr[idx]==x){
        return idx;
    }
    return -1;
}




int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    // int p = lastIndex(arr, n-1, d, n);
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}
