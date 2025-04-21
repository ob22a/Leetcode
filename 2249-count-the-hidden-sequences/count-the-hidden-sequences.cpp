class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur=0;
        long long minimum=0,maximum=0;
        for(int d:differences){
            cur+=d;
            if(minimum>cur) minimum=cur;
            if(maximum<cur) maximum=cur;
        }
        long long low=lower-minimum,high=upper-maximum;
        
        return max(0LL,high-low+1);
    }
};