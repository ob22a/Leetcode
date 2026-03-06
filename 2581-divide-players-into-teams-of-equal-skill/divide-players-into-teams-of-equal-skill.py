class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        # 2 2 pair
        # there are n/2 pairs
        # each will have total sum*2/n
        n=len(skill)
        total = sum(skill)
        if total%(n//2)!=0:
            return -1

        target = total//(n//2)
        seen=defaultdict(int)
        count=0
        chemistry = 0

        for s in skill:
            if target-s in seen:
                count+=1
                chemistry+=s*(target-s)
                if seen[target-s]==1:
                    seen.pop(target-s)
                else:
                    seen[target-s]-=1

            else: seen[s]+=1

        # print(target)
        # print(count)
        if count!=n//2:
            return -1

        return chemistry