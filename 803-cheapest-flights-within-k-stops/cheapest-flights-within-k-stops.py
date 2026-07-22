class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph=defaultdict(list)
        for fr,to,pr in flights:
            graph[fr].append((to,pr))
        
        dist = [float('inf')]*n
        dist[src]=0

        que=deque([(0,src,0)])

        while que:
            #print(que)
            stops,pos,cost = que.popleft()

            if stops>k:
                continue
            
            for nei,c in graph[pos]:
                if cost + c < dist[nei] and stops<=k:
                    dist[nei]=cost+c
                    que.append((stops+1,nei,cost+c))
                    
        return -1 if dist[dst]==float('inf') else dist[dst]