class Solution:
    def minOperations(self, s: str) -> int:
        sorted_str = "".join(sorted(s))

        if s==sorted_str: return 0
        if len(s)==2: return -1

        largest_char = max(s)
        smallest_char = min(s)

        if smallest_char==s[0] or largest_char==s[-1]: return 1
        if (largest_char==s[0] and s.count(largest_char)==1) and (smallest_char==s[-1] and s.count(smallest_char)==1):
            return 3
        
        return 2