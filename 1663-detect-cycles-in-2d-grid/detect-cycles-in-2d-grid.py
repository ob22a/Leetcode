class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m,n=len(grid),len(grid[0])
        seen = set()
        
        def dfs(i,j,start,prev):
            if i<0 or j<0 or i>=m or j>=n or grid[start[0]][start[1]]!= grid[i][j]:
                return False
            
            if (i,j) in seen:
                return True
            
            seen.add((i,j))
            p = (i,j)
            sol = False

            if prev!=(i+1,j):
                sol |= dfs(i+1,j,start,p)
            
            if prev!=(i,j+1):
                sol |= dfs(i,j+1,start,p)

            if prev!=(i,j-1):
                sol |= dfs(i,j-1,start,p)
            
            if prev!=(i-1,j):
                sol |= dfs(i-1,j,start,p)

            return sol


        for i in range(m):
            for j in range(n):
                if (i,j) not in seen and dfs(i,j,(i,j),None):
                    return True
        
        return False