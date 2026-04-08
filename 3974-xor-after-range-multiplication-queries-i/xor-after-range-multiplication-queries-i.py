class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        MOD = 1e9+7
        for l,r,k,v in queries:
            while l<=r:
                nums[l]=int((nums[l]*v)%MOD)
                l+=k
        
        sol = nums[0]
        for i in range(1,n):
            sol = sol ^ nums[i]
        
        return sol