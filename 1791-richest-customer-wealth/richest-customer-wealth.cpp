class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sol=0;
        for(const vector<int>& vec:accounts){
            int val=0;
            for(const int& n:vec){
                val+=n;
            }
            sol=max(sol,val);
        }
        return sol;
    }
};