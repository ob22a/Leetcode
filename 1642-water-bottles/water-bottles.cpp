class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty =0, full=numBottles;
        int sol=0;

        while(full!=0){
            sol+=full;
            empty+=full;
            full = empty/numExchange;
            empty %= numExchange;
        }

        return sol;
    }
};