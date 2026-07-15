class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n=len(graph)
        # if there is no cycle then it is a safe node
        
        in_cycle=[False]*n
        in_path=[False]*n
        safe = [False] * n
        seen=[False]*n

        def detect_cycle(node):
            if safe[node]:
                return True

            if in_cycle[node] or in_path[node]:
                return False
            
            in_path[node]=True
            seen[node]=True

            for next_node in graph[node]:
                if in_cycle[next_node] or not detect_cycle(next_node):
                    in_cycle[node]=True
                    return False
            
            in_path[node] = False
            safe[node] = True
            
            return True

        for i in range(n):
            if in_cycle[i]:
                continue
                
            detect_cycle(i)
        
        return [i for i in range(n) if not in_cycle[i]]