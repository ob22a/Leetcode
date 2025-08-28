class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>freq;
        for(int num:deck) freq[num]++;
        int x=freq[deck[0]];
        for(const auto& p:freq){
            x=__gcd(x,p.second);
            if(x==1) return false;
        }
        return true;
    }
};