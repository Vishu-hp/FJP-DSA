// https://practice.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    // Code here
	     vector<int>deg(V,0);
	    int cnt=0;
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            deg[i]++;
	        }
	        if(deg[i]%2==0){
	            cnt++;
	        }
	    }
	    
	    if(cnt==V){
	        return 1;
	    }
	    return 0;
	}

};
