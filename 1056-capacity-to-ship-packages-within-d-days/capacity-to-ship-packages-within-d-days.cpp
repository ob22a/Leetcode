class Solution {
public:
    int numberDays(const vector<int>& weights,const long long& capacity){
        int days=1;
        long long sum=0;
        for(int w:weights){
            if(w>capacity) return INT_MAX;
            if(sum+w>capacity){
                days++;
                sum=w;
            }
            else sum+=w;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long l=*max_element(weights.begin(),weights.end());
        long long r=0;
        for(int num:weights) r+=num;

        while(l<r){
            long long m=l+(r-l)/2;
            if(numberDays(weights,m)>days) l=m+1;
            else r=m;
        }
        return l;
    }
};