class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        total = 0
        sol = 0
        seen = defaultdict(int)
        seen[0]=-1

        for idx in range(n):
            total += nums[idx]
            mod = total%k
            if mod in seen:
                if idx-seen[mod]>=2:
                    return True
            else: seen[mod]=idx
        
        return False 