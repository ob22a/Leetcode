class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        n=len(nums)
        
        mask=0
        left=0
        sol=0
        
        for right in range(n):
            while mask&nums[right]!=0:
                mask^=nums[left]
                left+=1
            
            sol=max(sol,right-left+1)
            mask|=nums[right]
        
        return sol