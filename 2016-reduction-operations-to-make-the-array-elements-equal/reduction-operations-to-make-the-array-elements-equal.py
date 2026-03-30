class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort(reverse=True)

        sol = 0
        prev = -1

        for i in range(n):
            if nums[i]!=prev:
                sol+=i
                prev=nums[i]
        
        return sol