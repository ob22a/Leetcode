class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        
        count = 1
        left = 0
        cur_num = 0

        for right in range(n):
            if right>0 and nums[right]==nums[right-1]:
                count+=1
            else:
                count=1

            nums[left]=nums[right]

            if count<=2:
                left+=1
        
        return left    