class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        bool players[50]={};
        int current=0,pos=1;
        while(!players[current]){
            players[current]=true;
            current=(current+(pos*k))%n;
            ++pos;
        }
        vector<int>sol;
        for(int i=0;i<n;++i){
            if(!players[i]) sol.emplace_back(i+1);
        }
        return sol;
    }
};