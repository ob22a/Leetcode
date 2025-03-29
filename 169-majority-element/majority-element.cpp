class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Applying Boyer-Moore Voting algorithm

        int candidate=0,vote=0;
        for(int num:nums){
            if(vote==0) candidate=num;
            if(candidate==num) ++vote;
            else --vote;
        }
        return candidate;
    }
};