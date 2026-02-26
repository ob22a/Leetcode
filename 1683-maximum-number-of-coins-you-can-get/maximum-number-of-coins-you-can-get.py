class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        # 1 2 4 4 7 8
        piles.sort()
        coins = 0 
        n = len(piles)

        for i in range(n//3,n,2):
            coins+=piles[i]

        return coins