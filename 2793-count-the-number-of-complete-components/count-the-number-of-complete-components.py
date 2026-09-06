class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        sol = 0
        graph = defaultdict(list)

        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)

        seen  = [False]*n
        sol = 0
        
        def dfs(node,cmp):
            seen[node]=True
            cmp.append(node)

            for nei in graph[node]:
                if not seen[nei]:
                    dfs(nei,cmp)
        
        for node in range(n):
            if seen[node]:
                continue
            
            component = []
            dfs(node,component)
            is_complete = True

            for n in component:
                if len(graph[n])!=len(component)-1:
                    is_complete=False
                    break
            
            if is_complete:
                sol+=1
        
        return sol