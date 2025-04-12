class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=0, candidate2=0, vote1=0, vote2=0;
        vector<int> winners;
        for(int num:nums){
            if(candidate1==num) ++vote1;
            else if(candidate2==num) ++vote2;
            else if(vote1==0){
                candidate1=num;
                ++vote1;
            }
            else if(vote2==0){
                candidate2=num;
                ++vote2;
            }
            else{
                --vote1;
                --vote2;
            }
        }
        vote1=0;
        vote2=0;

        for(int num:nums){
            if(num==candidate1) ++vote1;
            else if(num==candidate2) ++vote2;
        }

        if(vote1>nums.size()/3) winners.push_back(candidate1);
        if(vote2>nums.size()/3) winners.push_back(candidate2);

        return winners;
    }
};
