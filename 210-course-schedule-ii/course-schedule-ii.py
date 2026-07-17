class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # topo sort
        stk=[]

        # generate graph
        graph=defaultdict(list)
        for x,y in prerequisites:
            graph[y].append(x)

        in_path=[False]*numCourses
        safe=[False]*numCourses
        
        def dfs(i):
            if in_path[i]:
                return True
            if safe[i]:
                return False

            in_path[i]=True

            for n in graph[i]:
                if dfs(n):
                    return True
            
            in_path[i]=False
            safe[i]=True
            stk.append(i)

            return False
        
        for i in range(numCourses):
            if dfs(i):
                return []
        
        return stk[::-1]