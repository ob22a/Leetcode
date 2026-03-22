class Solution:
    def maxJump(self, stones: List[int]) -> int:
        n = len(stones)
        sol = stones[1]-stones[0]
        
        for i in range(3,n,2):
            sol = max(sol,stones[i]-stones[i-2])
        
        for i in range(2,n,2):
            sol = max(sol,stones[i]-stones[i-2])
        
        return sol