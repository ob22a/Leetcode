class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        reversed_str = s[::-1]
        for i in range(n):
            if s[:i]+s[i+1:] == reversed_str[:n-i-1]+reversed_str[n-i:]:
                return True
        
        return False