class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n=len(s)
        count_t = Counter(t)
        count_s = defaultdict(int)

        def isValid():
            for char,count in count_t.items():
                if count_s[char]<count: return False
            
            return True
        
        left=0
        length = float('inf')
        startIdx = -1
        endIdx = -1

        for right in range(n):
            count_s[s[right]]+=1
            while isValid():
                size = right-left+1
                if size<length:
                    startIdx=left
                    endIdx=right
                    length = size
                
                if count_s[s[left]]<=1:
                    count_s.pop(s[left])
                else:
                    count_s[s[left]]-=1
                
                left+=1

        return "" if startIdx==-1 else s[startIdx:endIdx+1]