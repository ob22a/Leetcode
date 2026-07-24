class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n=len(grid)
        sz=n*n
        parent=[i for i in range(sz)]
        size=[1]*sz

        def find(x):
            if parent[x]==x:
                return x
            
            parent[x]=find(parent[x])
            return parent[x]
        
        def union(x,y):
            px=find(x)
            py=find(y)

            #print("Union",x,y,px,py)

            if px==py:
                return False

            if size[px]>size[py]:
                parent[py]=px
                size[px]+=size[py]
            else:
                parent[px]=py
                size[py]+=size[px] 
            
            return True
        
        seen=[False]*sz
        def bfs(i,j,prev):
            cur = i*n+j

            if not(0<=i<n) or not(0<=j<n) or seen[cur] or grid[i][j]==0:
                return
            
            seen[cur]=True
            #print(cur,prev)
            if prev is not None: union(cur,prev)

            for dx,dy in [(1,0),(0,1),(0,-1),(-1,0)]:
                bfs(i+dx,j+dy,cur)

        has_zero=False
        for i in range(n):
            for j in range(n):
                if grid[i][j]==1:
                    bfs(i,j,None)
                else:
                    has_zero=True
        
        #print(parent,size)
        if not has_zero:
            return sz
        
        sol=0
        for i in range(n):
            for j in range(n):
                if grid[i][j]==0:
                    island_sz=1
                    seen=set()

                    for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
                        nx=i+dx
                        ny=j+dy
                        idx=nx*n+ny

                        if 0<=nx<n and 0<=ny<n and grid[nx][ny]:
                            p=find(idx)
                            if p not in seen: island_sz+=size[p]
                            seen.add(p)
                    
                    sol=max(sol,island_sz)
        
        return sol