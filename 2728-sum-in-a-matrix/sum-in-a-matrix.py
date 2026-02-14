class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        score = 0
        n,m = len(nums),len(nums[0])

        for i in range(n):
            nums[i].sort()

        for col in range(m):
            val = 0
            for row in range(n):
                val = max(val,nums[row][col])
            score+=val
        
        return score