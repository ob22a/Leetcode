class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        score = 0
        unique = set()
        left = 0
        cur_sum = 0

        for right in range(n):
            while nums[right] in unique:
                unique.remove(nums[left])
                cur_sum-=nums[left]
                left+=1
            
            cur_sum+=nums[right]
            unique.add(nums[right])
            score=max(score,cur_sum)
        
        return score