class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        sol = float('inf')

        # let the heuristic be the manhatten distance
        mapp = {1:(0,0),2:(0,1),3:(0,2),4:(1,0),5:(1,1),0:(1,2)}
        seen = {tuple(tuple(row) for row in board)}
        dir = [(1,0),(0,1),(-1,0),(0,-1)]

        def heuristic(brd):
            diff = 0
            for i in range(2):
                for j in range(3):
                    x,y = mapp[brd[i][j]]
                    diff += abs(x-i) + abs(y-j)
            
            return diff

        pq = [(heuristic,0,board)]
        
        while pq:
            _,cnt,b = heapq.heappop(pq)
            
            isSolved = True
            x,y=-1,-1
            
            for i in range(2):
                for j in range(3):
                    cx,cy = mapp[b[i][j]]
                    if b[i][j]==0:
                        x,y = i,j
                    if cx!=i or cy!=j:
                        isSolved=False
            
            if isSolved:
                return cnt
            
            for dx,dy in dir:
                nx = x+dx
                ny = y+dy

                if 0<=nx<=1 and 0<=ny<=2:
                    b[x][y],b[nx][ny]=b[nx][ny],b[x][y]
                    tp = tuple(tuple(row) for row in b)

                    if not tp in seen:
                        seen.add(tp)
                        heapq.heappush(
                            pq,
                            (heuristic(b)+cnt+1,cnt+1,[row[:] for row in b])
                        )
                    
                    b[x][y],b[nx][ny]=b[nx][ny],b[x][y]
                
        return -1