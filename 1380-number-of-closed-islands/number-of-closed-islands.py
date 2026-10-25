class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        seen=set()
        m,n = len(grid),len(grid[0])

        def dfs(i,j):
            if not (0<=i<m) or not(0<=j<n) or (i,j) in seen or grid[i][j]==1:
                return
            
            # Change 0s to 1
            grid[i][j]=1
            dfs(i+1,j)
            dfs(i,j+1)
            dfs(i-1,j)
            dfs(i,j-1)
        
        for i in range(m):
            if grid[i][0]==0: dfs(i,0)
            if grid[i][n-1]==0: dfs(i,n-1)
        
        for j in range(n):
            if grid[0][j]==0: dfs(0,j)
            if grid[m-1][j]==0: dfs(m-1,j)
        
        sol = 0
        
        for i in range(1,m-1):
            for j in range(1,n-1):
                if grid[i][j]==0:
                    sol+=1
                    dfs(i,j)
        
        return sol