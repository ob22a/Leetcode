class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # when incoming num is smaller is smaller just add to num 
        # if left(max) is moved or not part then popleft

        n = len(nums)
        dq = deque()
        sol = []
        left = 0

        for right in range(n):
            # Remove if the window past the number
            while dq and right-dq[0]>=k:
                dq.popleft()

            while dq and nums[dq[-1]]<nums[right]:
                dq.pop()

            dq.append(right)
            if right-left+1 == k:
                sol.append(nums[dq[0]])
                left+=1
        
        return sol
            