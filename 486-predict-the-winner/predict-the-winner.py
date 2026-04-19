class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        
        # def f(i,j):
        #     if i==j:
        #         return nums[i]
            
        #     return max(nums[i]-f(i+1,j),nums[j]-f(i,j-1))
        # return f(0,n-1)>=0

        dp = [[0]*n for _ in range(n)]

        for i in range(n):
            dp[i][i]=nums[i]

        #print(dp)
        
        for i in range(n-1,-1,-1):
            for j in range(i+1,n):
                dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1])
        
        #print(dp)
        
        return dp[0][n-1]>=0
        
        