class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        sorted_unique_nums = sorted(set(nums))
        max_valid_window = 0

        left, right = 0, len(sorted_unique_nums)-1

        for right in range(len(sorted_unique_nums)):
            while sorted_unique_nums[right] - sorted_unique_nums[left] > n - 1:
                left += 1
            
            max_valid_window=max(max_valid_window,right-left+1)
        
        return n - max_valid_window