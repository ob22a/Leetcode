class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Fast and slow pointers
        j = 0
        n = len(nums)

        for i in range(n):
            if nums[i]!=0:
                nums[j],nums[i]=nums[i],nums[j]
                j+=1