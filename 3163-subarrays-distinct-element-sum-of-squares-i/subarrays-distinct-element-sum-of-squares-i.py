class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n=len(nums)
        sol = 0

        for i in range(n):
            for j in range(i,n):
                sol += len(set(nums[i:j+1]))**2

        return sol