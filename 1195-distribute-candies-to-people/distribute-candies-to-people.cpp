class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int amount=1;
        vector<int> sol(num_people,0);
        for(int idx=0;candies>0; ++amount,++idx){
            int val=min(amount,candies);
            candies-=val;
            sol[idx%num_people]+=val;
        }
        return sol;
    }
};