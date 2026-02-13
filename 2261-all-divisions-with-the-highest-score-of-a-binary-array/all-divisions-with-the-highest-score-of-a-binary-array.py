class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        # 0's in left and 1's in right
        n = len(nums)
        total_ones = nums.count(1)
        left = 0
        right = total_ones
        score = left + right

        sol = []
        for idx,num in enumerate(nums):
            if score==left+right:
                sol.append(idx)
            elif score<left+right:
                score=left+right
                sol = [idx]
            
            if num==0: left+=1
            else: right-=1

        if n-total_ones == score: sol.append(n)
        elif n-total_ones>score: sol=[n]
        
        return sol