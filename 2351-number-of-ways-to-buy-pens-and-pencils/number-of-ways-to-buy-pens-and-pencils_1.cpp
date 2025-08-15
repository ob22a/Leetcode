class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long sol=0;
        int small=min(cost1,cost2);
        int large=max(cost1,cost2);
        for(int val=total;val>=0;val-=large){
            sol+=(val/small)+1;
        }
        return sol;
    }
};
