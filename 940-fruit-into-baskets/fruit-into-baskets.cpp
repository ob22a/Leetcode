class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> trees;
        trees.reserve(3); // Maximum amount of tree type + 1 
        int amount=0;
        for(int r=0, l=0;r<fruits.size();++r){
            trees[fruits[r]]++;
            while(trees.size()>2){
                if(--trees[fruits[l]]==0) trees.erase(fruits[l]);
                ++l;
            }
            amount=max(amount,r-l+1);
        }
        return amount;
    }
};