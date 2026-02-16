class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        # diff is smaller than min
        n = len(nums)
        sol = 0
        
        for idx1 in range(n):
            for idx2 in range(idx1,n):
                if abs(nums[idx1]-nums[idx2])<=min(nums[idx1],nums[idx2]):
                    sol = max(sol,nums[idx1]^nums[idx2])

        return sol
