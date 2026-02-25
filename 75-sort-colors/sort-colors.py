class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Counting sort is the best option but since it is not in place I'll go with insertion
        n = len(nums)
        for i in range(1,n):
            j=i
            val = nums[j]

            while j>0 and nums[j-1]>val:
                nums[j]=nums[j-1]
                j-=1
            
            nums[j]=val

        