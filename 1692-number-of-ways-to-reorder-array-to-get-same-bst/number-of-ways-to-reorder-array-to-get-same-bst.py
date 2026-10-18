class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD = 10**9+7

        def rec(nums):
            n = len(nums)
            if n<3:
                return 1
            
            left = [x for x in nums if x<nums[0]]
            right = [x for x in nums if x>nums[0]]

            return rec(left)*rec(right)*comb(n-1,len(left)) % MOD
        
        return (rec(nums)-1)%MOD # remove the original combination