class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int totalOnes=0, leftZeros=0, leftOnes=0,maxScore=-1;
        vector<int> indices;
        for(int num:nums){
            if(num==1) ++totalOnes;
        }

        for(int i=0;i<=nums.size();++i){
            /*
            //The comparision cases are placed first so is mimics the division starting from one that is empty at the left and one that is empty at the right
            */
            int rightOnes=totalOnes-leftOnes;
            int score=leftZeros+rightOnes;

            if(score>maxScore){
                indices.clear();
                maxScore=score;
                indices.push_back(i);
            }
            else if (maxScore==score){
                indices.push_back(i);
            }

            if(i<nums.size()){
                if(nums[i]==0) ++leftZeros;
                else ++leftOnes; // Since it is binary array there is no other case
            }
            
        }
        return indices;
    }
};