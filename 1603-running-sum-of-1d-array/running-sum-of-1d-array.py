class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n = len(nums)
        sol = nums[:]

        for i in range(1,n):
            sol[i]+=sol[i-1]
        
        return sol