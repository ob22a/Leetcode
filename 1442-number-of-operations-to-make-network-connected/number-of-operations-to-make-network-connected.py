class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        size=[1]*n
        parents=[i for i in range(n)]

        def find(x):
            if x==parents[x]:
                return x
            
            parents[x]=find(parents[x])
            return parents[x]
                
        def union(x,y):
            px=find(x)
            py=find(y)

            if px>py:
                parents[py]=px
                size[px]+=size[py]
            else:
                parents[px]=py
                size[py]+=size[px]

        additional_connection=0
        for u,v in connections:
            if find(u)!=find(v):
                union(u,v)
            else:
                additional_connection+=1
        
        for c in range(n):
            find(c)
        
        sol = len(set(parents))-1

        if additional_connection<sol:
            return -1
        
        return sol