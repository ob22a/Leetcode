class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadendSet = set(tuple(map(int, de)) for de in deadends)
        target_digits = list(map(int, target))
        
        def heuristic(s):
            dist = 0
            for i in range(4):
                diff = abs(s[i] - target_digits[i])
                dist += min(diff, 10 - diff)
            return dist
        
        start = [0, 0, 0, 0]
        
        if tuple(start) in deadendSet:
            return -1
        
        pq = [(heuristic(start), 0, start)]
        seen = set([tuple(start)])
        
        while pq:
            _, cnt, val = heapq.heappop(pq)
            
            if val == target_digits:
                return cnt
            
            for i in range(4):
                for inc in [1, -1]:
                    val[i] = (val[i] + inc) % 10
                    tp = tuple(val)
                    
                    if tp not in seen and tp not in deadendSet:
                        seen.add(tp)
                        heapq.heappush(
                            pq,
                            (cnt + 1 + heuristic(val), cnt + 1, val[:])
                        )
                    
                    val[i] = (val[i] - inc) % 10
        
        return -1