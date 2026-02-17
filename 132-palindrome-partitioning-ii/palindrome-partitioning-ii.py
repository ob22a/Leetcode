class Solution:
    def minCut(self, s: str) -> int:
        # since all single characters are palindromes answer always exists
        #  have a range i,j and check for that being a palindrome if not continue with partion 
        n = len(s)

        # def partition(i):
        #     if i>=n:
        #         return 0
        #     sol = n-1
        #     cur_prt = ""
        #     for k in range(i,n):
        #         cur_prt+=s[k]
        #         if cur_prt==cur_prt[::-1]:
        #             if k==n-1:
        #                 sol = 0
        #             else: 
        #                 sol = min(sol,1+ partition(k+1))
        #     return sol
        
        # Tabulate this 

        dp = [n-1]*(n+1)
        for i in range(n-1,-1,-1):
            cur_prt = ""
            for k in range(i,n):
                cur_prt+=s[k]
                if cur_prt==cur_prt[::-1]:
                    if k==n-1:
                        dp[i]=0
                        break
                    else:
                        dp[i]=min(dp[i],1+dp[k+1])
            

        return dp[0]