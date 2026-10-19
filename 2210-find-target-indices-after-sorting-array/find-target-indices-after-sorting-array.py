class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        return [idx for idx,num in enumerate(sorted(nums)) if num==target]