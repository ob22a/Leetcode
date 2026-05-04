class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        n=len(s)

        sol = []

        for mask in range(1<<n):
            ans = list(s)
            numModified=False
            for idx in range(n):
                if s[idx].isalpha() and mask&(1<<idx):
                    if ans[idx].isupper():
                        ans[idx]=ans[idx].lower()
                    else:
                        ans[idx]=ans[idx].upper()
                        
                elif s[idx].isdigit() and mask&(1<<idx):
                    numModified=True
                    break
            
            if not numModified: sol.append("".join(ans))
        
        return sol