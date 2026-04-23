class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return 0

        l=1
        r=n-2

        while l<=r:
            m=(l+r)//2
            if nums[m-1]<nums[m] and nums[m+1]<nums[m]:
                return m
            elif nums[m+1]>nums[m]:
                l=m+1
            else:
                r=m-1
        
        if nums[0]>nums[1]:
            return 0
        
        return n-1