class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sol = sorted(score, reverse=True)
        mapp = {}
        n = len(score)
        rank = 4
        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]

        for i in range(n):
            if i<3:
                mapp[sol[i]]=medals[i]
            else:
                mapp[sol[i]]=str(rank)
                rank+=1
        
        for i in range(n):
            sol[i]=mapp[score[i]]
        
        return sol