class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)

        count_s1 = Counter(s1)
        count_s2 = defaultdict(int)
        left = 0

        for right in range(n2):
            count_s2[s2[right]]+=1
            if count_s1==count_s2:
                return True
            
            if right-left+1 == n1:
                count_s2[s2[left]]-=1
                if count_s2[s2[left]] == 0:
                    count_s2.pop(s2[left])
                left+=1
            
        return False