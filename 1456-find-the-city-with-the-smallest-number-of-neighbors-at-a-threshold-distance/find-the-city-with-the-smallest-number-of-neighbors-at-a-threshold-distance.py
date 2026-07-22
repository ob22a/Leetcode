class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        graph=[[float('inf')]*n for _ in range(n)]
        for u,v,w in edges:
            graph[u][v]=w
            graph[v][u]=w
            
            graph[u][u]=0
            graph[v][v]=0
        
        #print(graph)
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if graph[i][k]==float('inf') or graph[k][j]==float('inf'):
                        continue 
                    
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])
        
        #print(graph)

        sol = -1
        best_cnt=float('inf')

        for i in range(n):
            cnt=0
            for j in range(n):
                if cnt>best_cnt:
                    continue
                
                if graph[i][j]<=distanceThreshold:
                    cnt+=1
            if cnt<=best_cnt:
                sol=i
                best_cnt=cnt
        
        return sol