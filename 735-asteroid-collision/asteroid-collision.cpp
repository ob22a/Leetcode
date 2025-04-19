class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>sol;
        
        sol.push_back(asteroids[0]);
        for(int j=1;j<asteroids.size();++j){
            if(asteroids[j]>0) sol.push_back(asteroids[j]);
            else{
                if(sol.empty() || sol.back()<0) sol.push_back(asteroids[j]);
                else if(abs(asteroids[j])>abs(sol.back())){
                    sol.pop_back();
                    j-=1;
                }
                else if(abs(asteroids[j])==abs(sol.back())) sol.pop_back();
            }
        }
        return sol;
    }
};