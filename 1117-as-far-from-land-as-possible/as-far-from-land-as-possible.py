class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [[-1]*n for _ in range(n)]
        seen =set()
        lands = deque() 

        hasZero = False
        for i in range(n):
            for j in range(n):
                if grid[i][j]==1:
                    lands.append((i,j,0))
                else:
                    hasZero=True
        
        while lands:
            x,y,dist = lands.popleft()
            if x<0 or y<0 or x>=n or y>=n or (x,y) in seen:
                continue

            seen.add((x,y))
            dp[x][y]=dist
            
            lands.append((x+1,y,dist+1))
            lands.append((x,y+1,dist+1))
            lands.append((x,y-1,dist+1))
            lands.append((x-1,y,dist+1))

        
        return max(max(row) for row in dp) if hasZero else -1