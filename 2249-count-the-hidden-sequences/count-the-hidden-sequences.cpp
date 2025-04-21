class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> prefixSum={0};
        long long minimum=prefixSum[0],maximum=prefixSum[0];
        for(int d:differences){
            prefixSum.push_back(prefixSum.back()+d);
            long long last=prefixSum.back();
            if(minimum>last) minimum=last;
            if(maximum<last) maximum=last;
        }
        long long low=lower-minimum,high=upper-maximum;
        
        return max(0LL,high-low+1);
    }
};