class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0]!=0:
            return -1
        
        n=len(grid)
        
        seen=set((0,0))
        pq = deque([(1,0,0)])

        while pq:
            l,i,j=pq.popleft()

            if i==n-1 and j==n-1:
                return l
            
            for dx in {1,0,-1}:
                for dy in {1,0,-1}:
                    x=i+dx
                    y=j+dy

                    if 0<=x<n and 0<=y<n and (x,y)!=(i,j) and (x,y) not in seen and grid[x][y]==0:
                        pq.append((l+1,x,y))
                        seen.add((x,y))
        
        return -1