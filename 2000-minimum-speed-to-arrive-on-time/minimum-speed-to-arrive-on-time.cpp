class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(n>ceil(hour)) return -1;

        long long l=1,r=1e7;
        while(l<r){
            int m=l+(r-l)/2;
            double time=0;
            for(int i=0;i<n-1;++i){
                time+=(dist[i]+m-1)/m;
            }
            time+=((double) dist[n-1])/m;
            if(time>hour) l=m+1;
            else r=m;
        }
        return l;
    }
};