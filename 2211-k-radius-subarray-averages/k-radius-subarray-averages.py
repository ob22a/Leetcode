class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        sol = [-1]*n

        total = 0
        left = 0

        for right in range(n):
            total+=nums[right]

            if right-left+1==2*k+1:
                sol[right-k]=total//(2*k+1)
                total-=nums[left]
                left+=1
        
        return sol
