class Solution:
    def find(self,x,parents) ->int:
        if parents[x]==x:
            return x
        
        parents[x]=self.find(parents[x],parents)
        return parents[x]
    
    def union(self,x,y,rank,parents): # by rank
        px=self.find(x,parents)
        py=self.find(y,parents)

        if px==py:
            return 
        
        if rank[px]<rank[py]:
            px,py=py,px
        
        parents[py]=px

        if rank[px]==rank[py]:
            rank[px]+=1

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n=len(isConnected)
        parents=[i for i in range(n)]
        rank = [0]*n

        for i in range(n):
            for j in range(n):
                if i!=j and isConnected[i][j]:
                    self.union(i,j,rank,parents)
        
        for i in range(n):
            parents[i] = self.find(i, parents)
        
        return len(set(parents))

