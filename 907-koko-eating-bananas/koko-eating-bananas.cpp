class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int m=l+(r-l)/2;
            int time=0;
            for(int num:piles) time+=(num+m-1)/m;
            if(time>h) l=m+1;
            else r=m;
        }
        return l;
    }
};