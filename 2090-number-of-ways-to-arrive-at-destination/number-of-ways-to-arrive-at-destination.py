class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = int(1e9 + 7)
        graph=defaultdict(list)

        for u,v,time in roads:
            graph[u].append((v,time))
            graph[v].append((u,time))
        
        times=[float('inf')]*n
        times[0]=0

        ways=[0]*n
        ways[0]=1

        pq=[(0,0)] # time, start

        while pq:
            time,u = heapq.heappop(pq)

            if time>times[u]:
                continue
            
            for v,t in graph[u]:
                if times[u] + t < times[v]:
                    times[v]=t+times[u]
                    ways[v]=ways[u]
                    heapq.heappush(pq,(times[v],v))
                elif times[u]+t==times[v]:
                    ways[v]=(ways[v]+ways[u])%MOD
        
        return ways[n-1]