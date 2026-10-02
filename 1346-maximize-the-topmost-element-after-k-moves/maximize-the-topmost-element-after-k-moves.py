class Solution:
    def maximumTop(self, nums: list[int], k: int) -> int:
        n = len(nums)
        if (n==1 and k%2): return -1
        if k>n: return max(nums)
        
        # claim: for a given we max can be max(nums[:k-1]+nums[k])

        sol = 0
        for i in range(k+1):
            if i!=k-1 and i<n:
                if nums[i]>sol: sol = nums[i]
        
        return sol