class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1);
        for(int i=1;i<=n;++i){
            sol[i]=sol[i>>1]+(i&1);
        }
        return sol;
    }
};