class Solution:
    def firstUniqChar(self, s: str) -> int:
        n = len(s)
        q = deque()
        cntr = defaultdict(int)

        for i in range(n):
            q.append(i)
            cntr[s[i]]+=1
        
        while q and cntr[s[q[0]]]>1:
            q.popleft()
        
        if not q:
            return -1
        
        return q[0]
