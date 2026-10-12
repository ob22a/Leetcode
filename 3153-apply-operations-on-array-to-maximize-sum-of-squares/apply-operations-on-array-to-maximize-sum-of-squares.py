class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        cnt = [0]*30

        for num in nums:
            for i in range(30):
                if num & (1<<i): cnt[i]+=1
        
        sol = 0

        for _ in range(k):
            cur = 0

            for i in range(29,-1,-1):
                if cnt[i]>0:
                    cur|=1<<i
                    cnt[i]-=1
                
            sol = (sol + cur*cur)%MOD
        
        return sol