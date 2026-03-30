class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = int(1e9+7)
        graph = defaultdict(list)

        for start,end,time in roads:
            graph[start].append((end,time))
            graph[end].append((start,time))

        dist = [float('inf')]*n
        ways = [0]*n 

        dist[0]=0
        ways[0]=1

        heap = [(0,0)]

        while heap:
            d, u = heappop(heap)
            
            if d > dist[u]:
                continue 
            
            for v, time in graph[u]:
                if dist[u] + time < dist[v]:
                    dist[v] = dist[u] + time
                    ways[v] = ways[u]
                    heappush(heap, (dist[v], v))
                elif dist[u] + time == dist[v]:
                    ways[v] = (ways[v] + ways[u]) % MOD
        
        return ways[n-1]