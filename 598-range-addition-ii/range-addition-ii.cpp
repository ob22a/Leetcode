class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(vector<int> vec:ops){
            m=min(m,vec[0]);
            n=min(vec[1],n);
        }
        return m*n; 
    }
};