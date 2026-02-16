class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        # diff is smaller than min
        n = len(nums)
        nums.sort()

        sol = 0

        l = 0
        r = 0

        while r<n:
            if nums[r]-nums[l]>nums[l]:
                l+=1
                continue
            for i in range(l,r):
                sol = max(sol,nums[i]^nums[r])
            r+=1

        return sol
