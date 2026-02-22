class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        n = len(nums)
        nums.sort()
        print(nums)
        sol = 0
        i = 0
        while i<n:
            start = nums[i][0]
            end = nums[i][1]

            while i<n-1 and nums[i+1][0]<=end:
                end = max(end,nums[i+1][1])
                i+=1
            
            sol+=end-start+1
            i+=1
        
        return sol
