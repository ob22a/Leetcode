class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True

        count = 0
        d1 = {}
        d2 = {}
        
        for char in s1:
            if char not in d1:
                d1[char]=1
            else: d1[char]+=1

        for char in s2:
            if char not in d2:
                d2[char]=1
            else: 
                d2[char]+=1

        if d1!=d2:
            return False
        
        for char1,char2 in zip(s1,s2):
            if not char1==char2:
                count+=1
        
        return count==2

        