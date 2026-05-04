class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        n=len(s)

        sol = []

        for mask in range(1<<n):
            ans = list(s)
            numModified=False
            for idx in range(n):
                if s[idx].isalpha() and mask&(1<<idx):
                    ans[idx]=ans[idx].swapcase()
                
                elif s[idx].isdigit() and mask&(1<<idx):
                    numModified=True
                    break
            
            if not numModified: sol.append("".join(ans))
        
        return sol