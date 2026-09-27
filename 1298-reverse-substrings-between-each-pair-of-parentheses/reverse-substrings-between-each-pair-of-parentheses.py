class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        
        def rec(i):
            sol = []

            while i<n and s[i]!=")":
                if s[i].isalpha():
                    sol.append(s[i])
                elif s[i]=="(":
                    inner, i = rec(i+1)
                    sol.append(inner[::-1])
                i+=1
            
            return "".join(sol), i
        
        ans,_ = rec(0)
        return ans