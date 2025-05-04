class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count=0;
        vector<int> freq(100,0);

        for(const auto& d:dominoes){
            int x=d[0],y=d[1];
            int key=(x>y)?(y*10+x):x*10+y;
            count+=freq[key];
            freq[key]++;
        }
        
        return count;
    }
};