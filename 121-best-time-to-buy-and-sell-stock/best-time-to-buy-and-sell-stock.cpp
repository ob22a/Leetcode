class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minimum=prices[0];
        for(int price:prices){
            if(price<minimum) minimum=price;
            else if((price-minimum)>maxProfit) maxProfit=price-minimum;
        }
        return maxProfit;
    }
};