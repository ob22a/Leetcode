class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection={};
        unordered_set<int> seen;
        for(int num:nums1) seen.insert(num);

        for(int num:nums2){
            if(seen.count(num)){
                intersection.push_back(num);
                seen.erase(num);
            }
        }

        return intersection;
    }
};