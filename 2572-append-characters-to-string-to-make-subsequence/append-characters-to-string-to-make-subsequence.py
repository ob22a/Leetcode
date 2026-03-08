class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        common_idx=0
        n1 = len(s)
        n2 = len(t)
        
        for i in range(n1):
            if common_idx==n2: break
            if s[i]==t[common_idx]:
                common_idx+=1
        
        return n2-common_idx