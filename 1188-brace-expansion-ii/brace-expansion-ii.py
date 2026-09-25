class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        n = len(expression)

        def combine(a,b,op="mul"):
            a = list(set(a))
            b = list(set(b))

            if not a: return b
            if not b: return a

            if op=="add":
                return list(set(a+b))

            sol = []
            
            for ch_a in a:
                for ch_b in b:
                    sol.append(ch_a+ch_b)
            
            return list(set(sol))
        
        def rec(i):
            res = []
            term = []

            while i<n and expression[i]!="}":
                if expression[i]==",":
                    res = combine(res,term,"add")
                    term = []
                elif expression[i]=="{":
                    inner,i = rec(i+1)
                    term = combine(term,inner)
                else:
                    term = combine(term,[expression[i]])
                
                i+=1
            
            res = combine(res,term,'add')
            return res,i
        
        sol,_ = rec(0)
        return sorted(sol)