#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess,int n,int r,int c,int upcomingMove){
  //write your code here
    if(r<0 || c<0 || r>=n || c>=n || upcomingMove> n*n || chess[r][c]!=-1){
        return;
    }

    if(upcomingMove == n*n){
        chess[r][c]= n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        chess[r][c]= -1;
        return;
    }

    chess[r][c] = upcomingMove;
    printKnightsTour(chess,n,r-2,c+1,upcomingMove+1);
    printKnightsTour(chess,n,r-1,c+2,upcomingMove+1);
    printKnightsTour(chess,n,r+1,c+2,upcomingMove+1);
    printKnightsTour(chess,n,r+2,c+1,upcomingMove+1);
    printKnightsTour(chess,n,r+2,c-1,upcomingMove+1);
    printKnightsTour(chess,n,r+1,c-2,upcomingMove+1);
    printKnightsTour(chess,n,r-1,c-2,upcomingMove+1);
    printKnightsTour(chess,n,r-2,c-1,upcomingMove+1);
    chess[r][c]=-1;
}
    
int main(){
    int n;
    cin>>n;
    int r,c;
    cin>>r>>c;

    vector<vector<int>>chess(n,vector<int>(n,-1));
    printKnightsTour(chess,n,r,c,1);
    return 0;    
}
