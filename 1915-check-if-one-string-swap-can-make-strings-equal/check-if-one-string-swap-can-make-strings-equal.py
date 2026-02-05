class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True

        count = 0

        if Counter(s1)!=Counter(s2):
            return False
        
        for idx in range(len(s1)):
            if not s1[idx]==s2[idx]:
                count+=1
        
        return count==2

        