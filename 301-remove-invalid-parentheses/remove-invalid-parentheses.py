class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # we can ignore letters
        # claim: we can just remove the first time we get in consistency and then that will be the smallest and then collect all the answers by backtracking

        min_removal = 0
        open = 0

        for c in s:
            if c=="(":
                open+=1
            elif c==")":
                if open==0:
                    min_removal+=1
                else:
                    open-=1
        
        min_removal+=open

        sol = []
        n=len(s)
        

        def rec(idx,ans,removal,cost):
            if removal<0 or cost<0:
                return

            if idx==n:
                if cost==0 and removal==0:
                    sol.append(ans)
                return
            
            if s[idx]!="(" and s[idx]!=")":
                rec(idx+1,ans+s[idx],removal,cost)
                return
            
            cst_at_idx = 1 if s[idx]=="(" else -1

            rec(idx+1,ans,removal-1,cost)
            rec(idx+1,ans+s[idx],removal,cost+cst_at_idx)
        
        rec(0,"",min_removal,0)
        return list(set(sol))