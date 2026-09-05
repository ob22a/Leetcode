class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n=len(nums)
        found = False
        
        max_pre = [0]*n 
        max_pre[0]=nums[0]

        min_suf = [float('inf')]*n
        min_suf[n-1]=nums[n-1]

        # build the prefix max
        for i in range(1,n):
            max_pre[i]=max(max_pre[i-1],nums[i])
        
        # build the suffix min
        for i in range(n-2,-1,-1):
            min_suf[i]=min(min_suf[i+1],nums[i])
        
        for i in range(n):
            if max_pre[i]-min_suf[i]<=k:
                return i
        
        return -1