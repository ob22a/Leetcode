class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n,m=len(heights),len(heights[0])
        size=n*m
        dist = [float('inf')]*size

        pq=[(0,0,0)] # cost i j

        while pq:
            cost,x,y=heapq.heappop(pq)

            if (x,y)==(n-1,m-1):
                return cost
            
            for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
                nx=x+dx
                ny=y+dy

                if 0<=nx<n and 0<=ny<m:
                    nc = max(cost,abs(heights[x][y]-heights[nx][ny]))
                    
                    if nc<dist[m*nx+ny]:
                        dist[m*nx+ny]=nc
                        heapq.heappush(pq,(nc,nx,ny))