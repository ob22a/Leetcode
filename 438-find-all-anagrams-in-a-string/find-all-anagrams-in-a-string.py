class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n1=len(s)
        n2=len(p)

        if n1<n2:
            return []
            
        count_p = Counter(p)
        count_s = defaultdict(int)

        start = 0
        while start<n2:
            count_s[s[start]]+=1
            start+=1
        
        left = 0
        sol = []

        for right in range(start,n1):
            if count_p==count_s:
                sol.append(left)
            
            count_s[s[right]]+=1
            count_s[s[left]]-=1

            if count_s[s[left]]==0:
                count_s.pop(s[left])
            
            left+=1
            #print(count_s)
        
        if count_p==count_s:
            sol.append(left)
        
        return sol