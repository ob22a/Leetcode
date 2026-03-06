class Solution:
    def compress(self, chars: List[str]) -> int:
        n=len(chars)
        count = 1
        sol = 0

        j=1
        for i in range(1,n+1):
            if i==n or chars[i-1]!=chars[i]:
                val = str(count)
                if val=="1":
                    if i<n: chars[j]=chars[i]
                    j+=1
                    sol+=1
                    continue

                for c in val:
                    chars[j]=c
                    j+=1
                
                if i!=n: chars[j]=chars[i]
                j+=1
                
                sol+=len(str(count))+1
                count=1
            else:
                count+=1

        #print(j)
        
        return sol