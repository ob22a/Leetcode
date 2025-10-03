class Solution {
public:
    int f(vector<int>& prices,int idx,bool canBuy){
        if(idx==prices.size()) return 0;

        long long profit = 0;

        if(canBuy){
            profit = max(-prices[idx] + f(prices,idx+1,false), f(prices,idx+1,true));
        }
        else profit = max(prices[idx]+f(prices,idx+1,true),f(prices,idx+1,false));

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() + 1;
        vector<long long> prev(2,0);
        vector<long long> cur(2,0);

        for(int idx=n-2;idx>=0;--idx){
            cur[0] = max(prices[idx]+prev[1],prev[0]);
            cur[1] = max(-prices[idx]+prev[0], prev[1]);
            prev = cur;
        }

        return prev[1];
    }
};