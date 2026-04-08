class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        minQueue = deque()
        maxQueue = deque()
        sol = 0

        left = 0
        for right in range(n):
            # print(minQueue)
            # print(maxQueue)
            
            # Adding to maxqueue
            while maxQueue and nums[maxQueue[-1]]<nums[right]:
                maxQueue.pop()
            
            maxQueue.append(right)

            # Adding to minqueue

            while minQueue and nums[minQueue[-1]]>nums[right]:
                minQueue.pop()
            
            minQueue.append(right)

            while nums[maxQueue[0]]-nums[minQueue[0]]>limit:
                if maxQueue[0]==left:
                    maxQueue.popleft()
                if minQueue[0]==left:
                    minQueue.popleft()
                left+=1

            sol = max(sol,right-left+1)
        
        return sol