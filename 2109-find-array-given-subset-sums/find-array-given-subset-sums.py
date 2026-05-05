class Solution:
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        
        sol=[]
        while len(sums) > 1:
            num = sums[-1] - sums[-2] 
            countMap = Counter(sums)
            excluding = [] 
            including = []
            
            for x in sums:
                if countMap[x] > 0:
                    excluding.append(x)
                    including.append(x+num)
                    countMap[x] -= 1
                    countMap[x+num] -= 1
                    
			# Check validity of excluding set	
            if 0 in excluding:
                sums = excluding
                sol.append(num)
            else:
                sums = including
                sol.append(-1*num)
        
        return sol