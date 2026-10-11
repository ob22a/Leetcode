class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        sol = 0

        for i in range(n):
            if n%(i+1)==0: sol+=nums[i]**2
        
        return sol