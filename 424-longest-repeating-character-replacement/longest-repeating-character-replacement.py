class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        left = 0
        char_count = defaultdict(int)
        sol = 0

        for right in range(n):
            char_count[s[right]]+=1

            while right-left+1 - max(char_count.values())>k:
                char_count[s[left]]-=1
                left+=1
            
            sol = max(sol,right-left+1)
            
        return sol