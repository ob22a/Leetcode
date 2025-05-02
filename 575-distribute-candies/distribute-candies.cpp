class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> seen;
        int ans=0;
        int ind=0;
        while(ind<candyType.size() && ans<candyType.size()/2){
            if(!seen.count(candyType[ind])) ++ans;
            seen.insert(candyType[ind]);
            ++ind;
        }
        return ans;
    }
};