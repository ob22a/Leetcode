class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        expr = []
        cur = 0
        for c in expression:
            if c.isdigit():
                cur=cur*10+int(c)
            else:
                expr.append(cur)
                cur = 0
                expr.append(c)
        
        expr.append(cur)
        n = len(expr)

        ans = []

        @lru_cache(None)
        def p_dp(i,j):
            if i+1==j:
                return [expr[i]]
            
            sol = []

            for k in range(i,j):
                if not isinstance(expr[k],int):
                    left = p_dp(i,k)
                    right = p_dp(k+1,j)

                    match expr[k]:
                        case "+":
                            sol.extend([a + b for a in left for b in right])
                        case "-":
                            sol.extend([a-b for a in left for b in right])
                        case "*":
                            sol.extend([a*b for a in left for b in right])
                    
            return sol
               
        return p_dp(0,n)