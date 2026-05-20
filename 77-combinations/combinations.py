class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        sol = []
        temp = []

        def bkt(n,k,curIdx):
            if len(temp)==k:
                sol.append(temp[:])
                return
            
            for i in range(curIdx+1,n):
                temp.append(i+1)
                bkt(n,k,i)
                temp.pop()
        
        bkt(n,k,-1)

        return sol