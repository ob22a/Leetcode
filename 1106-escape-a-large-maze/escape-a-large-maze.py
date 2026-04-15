class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        n = len(blocked)
        block_limit = (n*(n-1))//2
        blocked_set = set(map(tuple, blocked))

        def bfs(start,destination):
            visited = set()
            queue = deque([tuple(start)])
            visited.add(tuple(start))

            d = [(1,0),(0,1),(-1,0),(0,-1)]

            while queue:
                x,y = queue.popleft()

                if [x,y] == destination:
                    return True

                for dx,dy in d:
                    nx = x+dx
                    ny = y+dy

                    if 0 <= nx < 10**6 and 0 <= ny < 10**6:
                        if (nx, ny) not in blocked_set and (nx, ny) not in visited:
                            visited.add((nx, ny))
                            queue.append((nx, ny))

                            if len(visited) > block_limit:
                                return True
            return False

        return bfs(source,target) and bfs(target,source)