class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m,n=len(grid1),len(grid1[0])
        
        seenLand = set()

        def dfs(i,j):
            if i<0 or i>=m or j<0 or j>=n or grid2[i][j]==0 or (i,j) in seenLand:
                return True
            
            seenLand.add((i,j))

            noZero = dfs(i-1,j) & dfs(i,j-1) & dfs(i+1,j) & dfs(i,j+1)

            if grid1[i][j]==0:
                return False
            
            return noZero
        
        sol = 0

        for i in range(m):
            for j in range(n):
                if grid2[i][j]==1 and (i,j) not in seenLand:
                    subIsland=dfs(i,j)

                    if subIsland: sol+=1
        
        return sol