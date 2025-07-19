class Solution {
public:
    int helper(const int& day,const vector<int>& bloomDay,const int& k){
        int no_boq=0,count=0;
        for(int num:bloomDay){
            if(num<=day){
                ++count;
                if(count==k){
                    no_boq++;
                    count=0;
                }
            }
            else count=0;
        }
        return no_boq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((1ll*m*k)>n) return -1;

        int l=1,r=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<r){
            int mid=l+(r-l)/2;
            int bouquets=helper(mid,bloomDay,k);
            if(bouquets<m) l=mid+1;
            else r=mid;
        }
        return l;
    }
};