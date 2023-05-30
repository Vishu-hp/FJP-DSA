// https://www.interviewbit.com/problems/merge-overlapping-intervals/

* Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval &i1, Interval &i2){
     return i1.start < i2.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    sort(A.begin(), A.end(), comp);
    Interval iv;
    iv.start = A[0].start;
    iv.end = A[0].end;
    
    for(int i=1;i<A.size();i++){
        int s = A[i].start;
        int e = A[i].end;
        
        if(iv.end >= s){
            iv.end = max(iv.end, e);
        }
        else{
            ans.push_back(iv);
            iv.start = s;
            iv.end = e;
        }
    }
    
    ans.push_back(iv);
    return ans;
}
