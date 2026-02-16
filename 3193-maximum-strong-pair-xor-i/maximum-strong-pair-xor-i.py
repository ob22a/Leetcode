class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        # diff is smaller than min
        sol = 0
        for num1 in nums:
            for num2 in nums:
                if abs(num1-num2)<=min(num1,num2):
                    sol = max(sol,num1^num2)

        return sol
