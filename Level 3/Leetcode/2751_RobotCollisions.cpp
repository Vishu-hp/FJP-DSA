// GREAT PROBLEM ON SIMULATION. GREAT LEARNING OF CONCEPT OF COLLISION. SOLVED LC-735 WITH SIMILAR CONCEPT OF COLLISION.
// INTUTION: COLLISION OCCURS WHEN WE HAD LAST STONE MOVING IN RIGHT AND CURRENT IN LEFT , OTHERWISE NO COLLISION.

class Solution {
public:
    class Pair{
        public:
        int p, h, idx ;
        char d;
        
        Pair(){}
        
        Pair(int p,int h,int idx,char d){
            this->p = p;
            this->h = h;
            this->idx = idx;
            this->d = d;
        }
    };
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Pair>v1;
        for(int i=0;i<positions.size();i++){
            v1.push_back(Pair(positions[i],healths[i],i,directions[i]));
        }
        
        sort(v1.begin(), v1.end(), [](const Pair &a,const Pair &b){
            return a.p < b.p;
        });
        
        vector<Pair>v2;
        
        for(auto x:v1){
            if(x.d == 'R'){
                v2.push_back(x);
                continue;
            }
            
            bool flag=false;
            while(v2.size()>0 && x.h >= v2.back().h && v2.back().d == 'R'){
                if(x.h == v2.back().h){
                    v2.pop_back();
                    flag = true;
                    break;
                }
                
                x.h--;
                v2.pop_back();
            }
            
            if(flag==false && v2.size()>0 && v2.back().h > x.h && v2.back().d == 'R'){
                v2.back().h--;
                flag=true;
            }
            
            if(flag==false){
                v2.push_back(x);
            }
        }
        
        sort(v2.begin(), v2.end(), [](const Pair &a, const Pair &b){
            return a.idx < b.idx;
        });
            
        vector<int>ans;
        for(auto x:v2){
            ans.push_back(x.h);
        }
        return ans;
    }
};
