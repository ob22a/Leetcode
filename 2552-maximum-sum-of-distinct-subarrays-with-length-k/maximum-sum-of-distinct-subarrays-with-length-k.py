class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n=len(nums)
        seen = set()
        left = 0
        total = 0
        sol = 0

        for right in range(n):
            while nums[right] in seen:
                seen.remove(nums[left])
                total-=nums[left]
                left+=1

            seen.add(nums[right])
            total+=nums[right]
            
            if right-left+1==k:
                sol = max(sol,total)
                total-=nums[left]
                seen.remove(nums[left])
                left+=1
        
        return sol