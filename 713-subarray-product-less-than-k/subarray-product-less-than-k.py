class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # Sliding window
        n=len(nums)
        l=0
        prod=1
        sol=0

        for r in range(n):
            prod*=nums[r]

            while l<=r and prod>=k:
                prod//=nums[l]
                l+=1
            
            if l<=r:        
                sol+=r-l+1

        return sol