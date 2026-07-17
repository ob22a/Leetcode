class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Attempt Kahn's Algo
        in_deg=[0]*numCourses
        graph=defaultdict(list)

        for x,y in prerequisites:
            in_deg[x]+=1
            graph[y].append(x)
        
        que = deque(list(i for i in range(numCourses) if in_deg[i]==0))
        completed=0

        while que:
            node=que.popleft()
            completed+=1

            for nbr in graph[node]:
                in_deg[nbr]-=1
                if in_deg[nbr]==0:
                    que.append(nbr)
        
        return numCourses==completed