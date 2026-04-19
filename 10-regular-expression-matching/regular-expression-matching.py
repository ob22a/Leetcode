class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # star then don't move and when i ends check if * is at the end then it is valid 
        # Branch when finding * we can ignore it or take it into account
        n1,n2=len(s),len(p)

        # def f(i,j):
        #     if i<0 and j<0:
        #         return True
            
        #     if j<0:
        #         return False
            
        #     if i<0:
        #         if p[j]=="*":
        #             return f(i,j-2)
        #         return False
            
        #     if p[j]=='*':
        #         noTake = f(i,j-2)
        #         take = False

        #         if p[j-1]=='.' or s[i]==p[j-1]:
        #              take = f(i-1,j)

        #         return take or noTake
            
        #     if p[j]=='.' or s[i]==p[j]:
        #         return f(i-1,j-1)
            
        #     return False
        
        # return f(n1-1,n2-1)

        prev = [False] * (n2+1)
        cur = [False] * (n2+1)

        prev[0] = True
        for j in range(2,n2+1,2):
            if p[j-1]=="*":
                prev[j] = prev[j-2]
        
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                sol = False
                if p[j-1]=="." or (p[j-1]!="*" and s[i-1]==p[j-1]):
                    sol = prev[j-1]

                if p[j-1]=="*":
                    noTake = cur[j-2]
                    take = False

                    if p[j-2]=="." or s[i-1]==p[j-2]:
                        take = prev[j]

                    sol = take or noTake
                cur[j] = sol
                
            prev=cur[::]

        return prev[n2]