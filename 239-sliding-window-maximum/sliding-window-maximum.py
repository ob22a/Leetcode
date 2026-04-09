class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        left = 0
        q=deque()
        
        sol = []
        
        for right in range(n):
            while q and nums[q[-1]]<nums[right]:
                q.pop()
            q.append(right)

            if right-left+1==k:
                if q[0]<left:
                    q.popleft()

                sol.append(nums[q[0]])
                left+=1
        
        return sol