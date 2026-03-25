class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # This might be partition dp
        # def rec(start,end):
        #     if end-start<=1:
        #         return 0 # It's still leaf node
            
        #     sol = float('inf')
        #     for k in range(start+1,end):
        #         cost = max(arr[start:k])*max(arr[k:end]) + rec(start,k) + rec(k,end)
        #         sol = min(sol,cost)
            
        #     return sol
        n = len(arr)
        
        # Since we need max for i to j we need to store that
        maxVal = [[0]*n for _ in range(n)]

        for i in range(n):
            maxVal[i][i] = arr[i]
            for j in range(i+1, n):
                maxVal[i][j] = max(maxVal[i][j-1], arr[j])
        
        dp = [[0]*n for _ in range(n)]
        for length in range(2,n+1):
            for start in range(n-length+1):
                end = start + length - 1
                dp[start][end] = float('inf')
        
                for k in range(start, end):
                    dp[start][end] = min(dp[start][end],
                        dp[start][k] +
                        dp[k+1][end] +
                        maxVal[start][k] * maxVal[k+1][end]
                    )
        
        return dp[0][n-1]