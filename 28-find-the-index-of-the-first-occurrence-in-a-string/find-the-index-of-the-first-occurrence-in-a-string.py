class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # KMP 
        n1,n2 = len(haystack),len(needle)
        if n2==1: return haystack.find(needle)

        lps = [0]*n2
        idx,pref_lps = 1,0

        while idx<n2:
            if needle[idx]==needle[pref_lps]:
                lps[idx] = pref_lps + 1
                pref_lps += 1 
                idx += 1
            elif pref_lps==0:
                idx+=1
            else:
                pref_lps = lps[pref_lps-1]
        
        i,j = 0,0

        while i<n1:
            if haystack[i]==needle[j]:
                i += 1
                j += 1
            elif j==0:
                i += 1
            else:
                j = lps[j-1]
            
            if j==n2: return i-n2
        
        return -1