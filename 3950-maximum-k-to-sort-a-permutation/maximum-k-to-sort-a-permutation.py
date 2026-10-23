class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        sol = ~0
        for i in range(len(nums)):
            if i!=nums[i]:
                sol &= nums[i]
        
        return 0 if sol==-1 else sol