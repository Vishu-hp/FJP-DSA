class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	// Complete the function
    	int mf=0,mins=1,start=0;
    	unordered_map<int,int>fr;
    	unordered_map<int,int>lft;
    	
    	for(int i=0;i<n;i++){
    	    int v = a[i];
    	    
    	    if(fr.count(v)==0){
    	        fr[v] = 1;
    	        lft[v] = i;
    	    }
    	    else{
    	        fr[v]++;
    	        
    	        if(fr[v] > mf){
    	            mf = fr[v];
    	            mins = i-lft[v]+1;
    	            start=lft[v];
    	        }
    	        else if(fr[v]==mf && i-lft[v]+1<mins){
    	            mins = i-lft[v]+1;
    	            start=lft[v];
    	        }
    	    }
    	}
    	
    	vector<int>ans;
    	for(int i=start;i<start+mins;i++){
    	    ans.push_back(a[i]);
    	}
    	return ans;
    }
};
