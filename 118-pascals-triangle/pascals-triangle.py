class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        sol = []

        for row in range(numRows):
            newRow = [1]*(row+1)
            
            for idx in range(1,row):
                newRow[idx]=sol[row-1][idx]+sol[row-1][idx-1]
            
            sol.append(newRow)
        
        return sol