class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        n = len(tickets)
        que = deque()

        for i,num in enumerate(tickets):
            que.append((num,i))
        
        time = 1
        while que:
            val,idx = que.popleft()
            if val==1 and idx==k:
                break
            
            if val>1:
                que.append((val-1,idx))
            time+=1
        
        return time
