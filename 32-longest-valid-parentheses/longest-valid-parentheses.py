class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0

        n = len(s)
        dp = [0]*n

        stk=[]
        sol=0

        for i in range(n):
            if s[i]==")":
                if stk:
                    start = stk.pop()
                    val = i-start+1
                    if start>0:
                        val+=dp[start-1]
                    
                    if val>sol:
                        sol=val
                    
                    dp[i]=val
            else:
                stk.append(i)
        
        return sol
