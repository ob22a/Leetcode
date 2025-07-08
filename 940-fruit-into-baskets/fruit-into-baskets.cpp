class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        array<int,100001> trees={}; // For scalability using hash map is better 
        int types=0;
        int amount=0;
        for(int r=0, l=0;r<fruits.size();++r){
            if(++trees[fruits[r]]==1) types++;
            
            while(types>2){
                if(--trees[fruits[l++]]==0) --types;
            }
            amount=max(amount,r-l+1);
        }
        return amount;
    }
};