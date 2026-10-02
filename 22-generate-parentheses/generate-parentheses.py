class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        sol = []
        
        def rec(op,cl,s):
            if len(s)==2*n:
                sol.append(s)
                return
            
            if op<n: rec(op+1,cl,s+"(")
            if cl<op: rec(op,cl+1,s+")")

        rec(0,0,"")
        return sol

            
