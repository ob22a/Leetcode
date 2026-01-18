class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // For each number find where it was supposed to be
        // If we did that using BS it would be log n 
        
        int n = nums.size();
        vector<int> arr;

        for(int num:nums){
            int left =0, right = arr.size();
            while(left<right){
                int mid = left + (right-left)/2;
                if(arr[mid]>=num) right=mid;
                else left = mid+1;
            }
            if (left == arr.size()) arr.push_back(num);
            else arr[left] = num;

        }

        int sol = arr.size();
        return sol;
    }
};