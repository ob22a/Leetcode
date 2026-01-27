class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        arr = copy.deepcopy(nums)
        n = len(nums)

        for idx in range(n):
            arr[idx]=nums[nums[idx]]

        return arr