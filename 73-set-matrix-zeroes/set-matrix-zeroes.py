class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m,n=len(matrix),len(matrix[0])

        zeroFirstCol = False

        for i in range(m):
            if matrix[i][0]==0:
                zeroFirstCol = True

            for j in range(1,n):
                if matrix[i][j]==0:
                    matrix[0][j]=0
                    matrix[i][0]=0

        for row in range(m-1,-1,-1):
            for col in range(n-1,0,-1):
                if matrix[row][0]==0 or matrix[0][col]==0:
                    matrix[row][col]=0
            if zeroFirstCol:
                matrix[row][0]=0