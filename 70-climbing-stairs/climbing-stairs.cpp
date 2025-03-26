class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo={1,2};
        if(n<=2) return memo[n-1];
        for(int i=0;i<n-2;++i){
            memo.push_back(memo[memo.size()-1]+memo[memo.size()-2]);
        }
        return memo[memo.size()-1];
    }
};