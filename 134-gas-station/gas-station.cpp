class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        // if Sum(cost)>Sum(gas) return -1;
        long long gas_sum = accumulate(gas.begin(),gas.end(),0ll);
        long long cost_sum = accumulate(cost.begin(),cost.end(),0ll);

        if(gas_sum<cost_sum) return -1;

        int start = 0;
        int tank = 0;

        for(int i=0;i<n;++i){
            tank += gas[i]-cost[i];
            if(tank<0){
                start = i+1;
                tank=0;
            }
        }

        return start;
    }
};