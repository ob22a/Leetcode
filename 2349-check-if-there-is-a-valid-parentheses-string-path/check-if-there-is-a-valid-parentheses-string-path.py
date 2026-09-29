class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        # in general (  should be greater than or equal to number of )
        # if we are at the end they should be equal

        m,n=len(grid),len(grid[0])
        if (m+n-1)%2 == 1 or grid[0][0]==')' or grid[m-1][n-1]=='(':
            return False

        # def f(k,i,j):
        #     if k<0:
        #         return False

        #     if i==m-1 and j==n-1:
        #         return k==0

        #     if i<m-1:
        #         change = 1 if grid[i+1][j]=="(" else -1
        #         if f(k+change,i+1,j):
        #             return True

        #     if j<n-1:
        #         change = 1 if grid[i][j+1]=="(" else -1
        #         if (k+change,i,j+1):
        #             return True
            
        #     return False
        
        # return f(1 if grid[0][0]=="(" else -1,0,0)


        dp = [[[False]*(m+n) for _ in range(n)] for _ in range(m)]
        dp[m-1][n-1][0] = True

        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i==m-1 and j==n-1:
                    continue 

                for k in range(m-i+n-j-1):
                    if i<m-1:
                        change = 1 if grid[i+1][j]=="(" else -1
                        new_k = k+change

                        if 0 <=new_k<m+n:
                            if dp[i+1][j][new_k]:
                                dp[i][j][k] = True

                    if j<n-1:
                        change = 1 if grid[i][j+1]=="(" else -1
                        new_k = k+change

                        if 0<=new_k<m+n:
                            if dp[i][j+1][new_k]:
                                dp[i][j][k] = True
        
        start_k = 1 if grid[0][0]=="(" else -1
        return dp[0][0][start_k]