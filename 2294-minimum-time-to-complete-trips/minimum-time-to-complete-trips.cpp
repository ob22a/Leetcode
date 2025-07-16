class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long r=1ll*(*min_element(time.begin(),time.end()))*totalTrips;
        while(l<r){
            long long m=l+(r-l)/2;
            long long total=0;
            for(int t:time) total+=m/t;
            if(total<totalTrips) l=m+1;
            else r=m;
        }
        return l;
    }
};