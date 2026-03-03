class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m,n = len(matrix),len(matrix[0])
        dp = [[0]*n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==1:
                    prev_square = 0
                    if i>0 and j>0: prev_square = min(
                        dp[i-1][j-1],
                        dp[i-1][j],
                        dp[i][j-1]
                    )

                    dp[i][j]=prev_square+1
        return sum(sum(val) for val in dp)