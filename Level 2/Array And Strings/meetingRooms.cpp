// https://www.interviewbit.com/problems/meeting-rooms/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    sort(A.begin(),A.end());
    
    int ans=1;
    pq.push(A[0][1]);
    
    for(int i=1;i<A.size();i++){
        int s = A[i][0];
        int e = A[i][1];
        
        if(s>=pq.top()){
            pq.pop();
            pq.push(e);
        }
        else{
            ans++;
            pq.push(e);
        }
    }
    return ans;
}
