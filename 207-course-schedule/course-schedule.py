class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # First detect cycle if cycle False if not True
        visited=[False]*numCourses
        in_path = [False]*numCourses
        has_cycle=[True]*numCourses

        # generate graph from prerequisites
        graph = defaultdict(list)
        for x,y in prerequisites:
            graph[y].append(x)


        def detect_cycle(i):
            if in_path[i]:
                return True
            
            if not has_cycle[i]:
                return False
            
            visited[i]=True
            in_path[i]=True
        
            for n in graph[i]:
                if detect_cycle(n):
                    return True
            
            in_path[i]=False
            has_cycle[i]=False

            return False
        
        for i in range(numCourses):
            if detect_cycle(i):
                return False
        
        return True