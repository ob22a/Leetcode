class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
            Imagine all the total possible combination and build recursive solution 
            to reach 0th step it costs 0
            to reach 1st step it costs cost[0]

            so to reach n
            f(n)=min(f(n-1)+cost[n-1],f(n-2)+cost[n-2])

            Using this rec soln we can use tabulation
        */
        int prev2=0, prev=0;
        int n=cost.size();
        
        for(int i=2;i<=n;++i){
            int cur=min(prev+cost[i-1],prev2+cost[i-2]);
            prev2=prev;
            prev=cur;
        }

        return prev;
    }
};