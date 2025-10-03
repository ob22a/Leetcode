class Solution {
public:
    int f(vector<int>& prices, int idx, bool canBuy, int am){
        if(am==0) return 0;
        if(idx==prices.size()) return 0;

        long long profit = 0;
        if(canBuy) profit = max(-prices[idx] + f(prices,idx+1,false,am), f(prices,idx+1,true,am));
        else profit = max(prices[idx] + f(prices,idx+1,true,am-1), f(prices,idx+1,false,am));

        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() + 1;
        vector<vector<int>> prev (2,vector<int>(k + 1,0));
        vector<vector<int>> cur (2,vector<int>(k + 1,0));

        for(int idx=n-2;idx>=0;--idx){
            for(int am=1;am<=k;++am){
                cur[0][am] = max(prices[idx] + prev[1][am-1], prev[0][am]);
                cur[1][am] = max(-prices[idx] + prev[0][am], prev[1][am]);
            }
            prev = cur;
        }

        return prev[1][k];
    }
};