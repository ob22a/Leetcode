class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        # n^2 is acceptable 
        sol = []
        for num in nums:
            count = 0 
            for other in nums:
                if other<num: count+=1
            sol.append(count)

        return sol