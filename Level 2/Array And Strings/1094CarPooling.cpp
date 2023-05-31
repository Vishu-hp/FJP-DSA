// https://leetcode.com/problems/car-pooling/

// RANGE ADDITION APPLICATION SOLUTION
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int maxD=-1;
        for(int i=0;i<n;i++){
            maxD = max(maxD,trips[i][2]);
        }
        
        vector<int>pass(maxD+2,0);
        
        for(int i=0;i<n;i++){
            int v = trips[i][0];
            int s = trips[i][1];
            int e = trips[i][2];
            
            pass[s] += v;
            pass[e] -= v;
        }
        
        
        int pSum=0;
        for(int i=0;i<maxD+1;i++){
            pSum += pass[i];
            if(pSum>capacity){
                return false;
            }
        }
        return true;
    }
};

// GENERAL WAY COMES TO MIND
class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }

    class Pair{
        public:
        int ep;
        int pas;

        Pair(){}

        Pair(int ep, int pas){
            this->ep = ep;
            this->pas =pas;
        }
    };

    class Comp{
        public:
        bool operator()(Pair &a, Pair &b){
            return a.ep > b.ep;
        }
    };

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comp);
        priority_queue<Pair, vector<Pair>, Comp>pq;
        int cp=0;
        
        for(int i=0;i<trips.size();i++){
            int p=trips[i][0];
            int f = trips[i][1];
            int t = trips[i][2];

            while(pq.size()>0 && pq.top().ep <= f){
                cp -= pq.top().pas;
                pq.pop();
            }
            

            cp += p;
            if(cp>capacity){
                return false;
            }
            pq.push(Pair(t,p));
        }
        return true;
    }
};
