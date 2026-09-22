class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m,n=len(grid),len(grid[0])
        seen_row=[False]*m

        count=0

        for i in range(m):
            cnt = 0
            for j in range(n):
                if grid[i][j]==1:
                    cnt+=1
                
            if cnt>1:
                seen_row[i]=True
                count+=cnt
        
        for j in range(n):
            cnt=0
            seen_cnt=0
            for i in range(m):
                if grid[i][j]==1:
                    if seen_row[i]:
                        seen_cnt+=1
                    cnt+=1
            
            if cnt>1:
                count+=cnt-seen_cnt
        
        return count