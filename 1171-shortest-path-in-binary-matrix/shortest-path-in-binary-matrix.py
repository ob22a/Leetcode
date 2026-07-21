class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n=len(grid)
        
        if grid[0][0]!=0 or grid[n-1][n-1]!=0:
            return -1
        
        fwd_len={(0,0):1}
        bwd_len={(n-1,n-1):1}

        fwd = deque([(0,0)])
        bwd = deque([(n-1,n-1)])

        while fwd and bwd:
            #print(fwd,bwd)
            fi,fj=fwd.popleft()
            bi,bj=bwd.popleft()

            cur_fwd_len = fwd_len[(fi,fj)]
            cur_bwd_len = bwd_len[(bi,bj)]

            if (fi,fj) in bwd_len:
                return bwd_len[(fi,fj)] + fwd_len[(fi,fj)] - 1
            elif (bi,bj) in fwd_len:
                return fwd_len[(bi,bj)] + bwd_len[(bi,bj)] - 1
            
            for dx in [1,0,-1]:
                for dy in [1,0,-1]:
                    fx=fi+dx
                    fy=fj+dy

                    if 0<=fx<n and 0<=fy<n and (fx,fy)!=(fi,fj) and (fx,fy) not in fwd_len and grid[fx][fy]==0:
                        fwd.append((fx,fy))
                        fwd_len[(fx,fy)]=cur_fwd_len+1
            
            for dx in [-1,0,1]:
                for dy in [-1,0,1]:
                    bx=bi+dx
                    by=bj+dy

                    if 0<=bx<n and 0<=by<n and (bx,by)!=(bi,bj) and (bx,by) not in bwd_len and grid[bx][by]==0:
                        bwd.append((bx,by))
                        bwd_len[(bx,by)]=cur_bwd_len+1
        
        return -1