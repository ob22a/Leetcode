class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int players[50]={};
        int current=0,pos=1;
        while(++players[current]<=1){
            current=(current+(pos*k))%n;
            ++pos;
        }
        vector<int>sol;
        for(int i=0;i<n;++i){
            if(players[i]==0) sol.emplace_back(i+1);
        }
        return sol;
    }
};