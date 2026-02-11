class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        sol = list(s)
        print(sol)
        for i in range(len(indices)):
            sol[indices[i]]= s[i]
        
        return ''.join(sol)