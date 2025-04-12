class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);
        }
        vector<int> intersection;
        unordered_map<int,int> count;

        for(int num:nums2) count[num]++;

        for(int num:nums1){
            if(count[num]>0){
                intersection.push_back(num);
                count[num]--;
            }
        }
        return intersection;
    }
};
