class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n=len(words)
        mask = [0]*n

        sol = 0

        for i in range(n):
            for c in words[i]:
                mask[i] |= 1<<(ord(c)-ord('a'))

            for j in range(i):
                if not (mask[i] & mask[j]):
                    sol = max(sol,len(words[i])*len(words[j]))
        
        return sol
