// PRACTICE PROBLEM ON CONCEPT OF PROBLEM LC-2751 OF COLLISIONS.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>help;
        for(auto x:asteroids){
            if(x > 0){
                help.push_back(x);
                continue;
            }

            bool flag=false;
            while(help.size()>0 && help.back()>0 && abs(x) >= help.back()){
                if(help.back() == abs(x)){
                    help.pop_back();
                    flag=true;
                    break;
                }

                help.pop_back();
            }

            if(flag==false && help.size() >0 && help.back()>0){
                flag=true;
            }

            if(flag == false){
                help.push_back(x);
            }
        }
        return help;
    }
};
