class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        n=len(nums)
        count = Counter(nums)
        sol=0

        candidates=set()
        for num in nums:
            candidates.add(num-k)
            candidates.add(num)
            candidates.add(num+k)
        
        nums.sort()
        for t in candidates:
            left_pos = bisect.bisect_left(nums,t-k)
            right_pos = bisect.bisect_right(nums,t+k)

            new_freq = count[t] + min(right_pos-left_pos-count[t],numOperations)
            sol=max(sol,new_freq)
        
        return sol