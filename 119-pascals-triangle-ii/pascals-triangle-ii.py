class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        sol = []

        for row in range(rowIndex+1):
            newRow = [1]*(row+1)
            
            for idx in range(1,row):
                newRow[idx]=sol[idx]+sol[idx-1]
            
            sol=newRow
        
        return sol