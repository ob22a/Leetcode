class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n = len(arr)
        lengths = defaultdict(int)

        sol = 1
        for num in arr:
            lengths[num] = 1 + lengths[num-difference]
            sol = max(sol,lengths[num])
        
        return sol