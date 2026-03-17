class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        
        n,m = len(matrix), len(matrix[0])
        # Also create prefix sum during initialization
        # sum[i][j] = sum[i-1][j] + sum[i][j-1] + sum[i-1][j-1] as long as it is valid

        self.prefixSum = [row[:] for row in matrix]
        
        for j in range(1,m):
            self.prefixSum[0][j]+=self.prefixSum[0][j-1]
        
        for i in range(1,n):
            self.prefixSum[i][0]+=self.prefixSum[i-1][0]

        for i in range(1,n):
            for j in range(1,m):
                self.prefixSum[i][j]+= self.prefixSum[i-1][j] + self.prefixSum[i][j-1] - self.prefixSum[i-1][j-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        # Sum of a region formula
        res = self.prefixSum[row2][col2]
        if row1 > 0:
            res -= self.prefixSum[row1 - 1][col2]
        if col1 > 0:
            res -= self.prefixSum[row2][col1 - 1]
        if row1 > 0 and col1 > 0:
            res += self.prefixSum[row1 - 1][col1 - 1]

        return res


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)