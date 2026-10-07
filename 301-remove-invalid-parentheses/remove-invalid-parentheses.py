class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def is_valid(s):
            open=0
            for ch in s:
                if ch=="(":
                    open+=1
                elif ch==")":
                    if open==0:
                        return False
                    open-=1
            return open==0
        
        left,right = 0,0

        for c in s:
            if c=="(":
                left+=1
            elif c==")":
                if left>0:
                    left-=1
                else:
                    right+=1
        
        sol=[]
        n=len(s)
        
        def rec(idx,left,right,ans):
            if left==0 and right==0:
                ans+=s[idx:]
                if is_valid(ans):
                    sol.append(ans)
                return
            
            if idx==n:
                return
            
            if s[idx]=="(" and left>0: rec(idx+1,left-1,right,ans)
            if s[idx]==")" and right>0: rec(idx+1,left,right-1,ans)

            rec(idx+1,left,right,ans+s[idx])
        
        rec(0,left,right,"")
        
        return list(set(sol))