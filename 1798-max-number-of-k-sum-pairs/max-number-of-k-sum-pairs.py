class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        seen =defaultdict(int)
        sol = 0
        n = len(nums)

        for i in range(n):
            if (k-nums[i]) in seen:
                sol+=1
                if seen[k-nums[i]]==1: seen.pop(k-nums[i])
                else: seen[k-nums[i]]-=1
            else:
                seen[nums[i]]+=1
        
        return sol