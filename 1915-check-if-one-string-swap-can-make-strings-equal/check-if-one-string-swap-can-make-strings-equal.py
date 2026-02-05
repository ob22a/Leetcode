class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True

        count = 0

        if Counter(s1)!=Counter(s2):
            return False
        
        for char1,char2 in zip(s1,s2):
            if not char1==char2:
                count+=1
        
        return count==2

        