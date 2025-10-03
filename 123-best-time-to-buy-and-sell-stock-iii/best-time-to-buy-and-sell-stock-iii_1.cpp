class Solution {
public:
    int f(vector<int>& prices, int idx, bool canBuy, int no){
        if(no>2) return -1e9;
        if(idx==prices.size()) return 0;

        long long profit = 0;

        if(canBuy) profit = max(-prices[idx] + f(prices,idx+1,false,no), f(prices,idx+1,true,no));
        else profit = max(prices[idx] + f(prices,idx+1,true, no+1), f(prices,idx+1,false,no));

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() + 1;
        vector<vector<long long>> prev(2,vector<long long>(4,0)); // canBuy*no
        vector<vector<long long>> cur(2,vector<long long>(4,0)); // canBuy*no

        prev[0][3] = -1e9; prev[1][3] = -1e9;
        cur[0][3] = -1e9; cur[1][3] = -1e9;

        for(int idx=n-2;idx>=0;--idx){
            for(int no = 2;no>=0 ; --no ){
                cur[0][no] = max(prices[idx] + prev[1][no+1], prev[0][no]);
                cur[1][no] = max(-prices[idx] + prev[0][no], prev[1][no]);
            }
            prev = cur;
        }

        return prev[1][0];
    }
};
