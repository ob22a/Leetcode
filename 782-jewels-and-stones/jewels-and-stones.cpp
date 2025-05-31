class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> stoneCount;
        for(const char& c:stones) stoneCount[c]++;
        int ans=0;
        for(const char& c:jewels) ans+=stoneCount[c];
        return ans;
    }
};