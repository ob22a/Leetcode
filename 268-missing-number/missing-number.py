class Solution(object):
    def missingNumber(self, nums):
        n = len(nums)

        for i in range(n):
            while nums[i] < n and nums[i] != nums[nums[i]]:
                j = nums[i] 
                nums[i], nums[j] = nums[j], nums[i]

        '''
            In Python, when you write a tuple assignment like nums[i], nums[nums[i]] = nums[nums[i]], nums[i], Python evaluates the entire right-hand side first before performing any assignments.
            This means that even if the current value of nums[i] should be skipped (e.g., nums[i] >= n), Python will still try to compute nums[nums[i]] and can raise an IndexError.
            To avoid this, you need to store nums[i] in a temporary variable first and use that in the assignment, ensuring no invalid indexing occurs.
            '''

        for i in range(n):
            if nums[i] != i:
                return i

        return n
