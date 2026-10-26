class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m,n = len(grid),len(grid[0])
        seen = set()

        def dfs(i,j):
            if not(0<=i<m) or not(0<=j<n) or (i,j) in seen or grid[i][j]==0:
                return 0
            
            seen.add((i,j))
            return grid[i][j]+ dfs(i+1,j) + dfs(i,j+1) + dfs(i-1,j) + dfs(i,j-1)
        
        sol = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j]!=0 and (i,j) not in seen:
                    score = dfs(i,j)
                    if score%k==0: sol+=1
        
        return sol