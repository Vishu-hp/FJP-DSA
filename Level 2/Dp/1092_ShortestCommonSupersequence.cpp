class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>>tab(m+1,vector<int>(n+1,-1));    
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    tab[i][j] = 0;
                }
                else{
                    if(str1[i-1] == str2[j-1]){
                        tab[i][j] = 1+tab[i-1][j-1];
                    }
                    else{
                        tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
                    }
                }
            }
        }

        int i=m, j=n;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(tab[i-1][j] > tab[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0){
            ans+= str1[i-1];
            i--;
        }

        while(j>0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
