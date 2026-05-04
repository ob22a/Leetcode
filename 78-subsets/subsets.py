class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        limit = 2**n
        sol = []

        for mask in range(limit):
            subset  = []
            for idx in range(n):
                if mask & (1<<idx):
                    subset.append(nums[idx])
            sol.append(subset)
    
        return sol