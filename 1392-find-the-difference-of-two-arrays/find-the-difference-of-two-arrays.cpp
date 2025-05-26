class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen1,seen2;
        vector<vector<int>> result(2);
        for(int num:nums1) seen1.insert(num);
        for(int num:nums2){
            seen2.insert(num);
        }     
        for(const int& num:seen1){
            if(seen2.find(num)==seen2.end()) result[0].push_back(num);
        }
        for(const int& num:seen2){
            if(seen1.find(num)==seen1.end()) result[1].push_back(num);
        }
        return result;
    }
};