class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        # When is it legal it is legal when r*c == row*col
        row,col = len(mat),len(mat[0])
        size = row*col

        if size!=r*c: return mat

        sol = [[0]*c for _ in range(r)]
        print(sol)
         
        for i in range(row):
            for j in range(col):
                linear_idx = i*col+j
                new_r = linear_idx//c
                new_c = linear_idx%c
                print(new_r,new_c)
                sol[new_r][new_c]=mat[i][j]

        return sol