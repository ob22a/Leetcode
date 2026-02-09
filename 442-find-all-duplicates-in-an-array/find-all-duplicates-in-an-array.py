class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        sol = set()
        i = 0 
        n = len(nums)

        while i < n:
            correct = nums[i]-1
            if nums[i] != nums[correct]:
                nums[i], nums[correct] = nums[correct], nums[i]
            else:
                if i != correct and nums[i] not in sol:
                    sol.add(nums[i])
                i += 1

        return list(sol)