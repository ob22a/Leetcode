class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount=0,evenCount=0;
        for(int num:position){
            if(num%2==0) evenCount++;
            else oddCount++;
        }
        return min(evenCount,oddCount);
    }
};