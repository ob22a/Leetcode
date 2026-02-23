class Solution:
    def candy(self, ratings: List[int]) -> int:
        # go from left and right and then collect the max for both directions 
        n = len(ratings)
        lr = [1]*n
        rl = [1]*n

        for i in range(1,n):
            if ratings[i]>ratings[i-1]: 
                lr[i]=lr[i-1]+1
        
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                rl[i]=rl[i+1]+1

        sol = 0
        for i in range(n):
            sol+=max(lr[i],rl[i])

        return sol
