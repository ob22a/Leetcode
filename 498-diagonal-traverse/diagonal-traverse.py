class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
       # diagonal up mean -1, +1
       # diagonal down mean +1, -1
       # passing boundary 
            # if past col then keep col add 1 to row
            # if past row then keep row add 1 to col

        sol = []
        m,n=len(mat),len(mat[0])
        up = True
        i,j=0,0

        while i<m and j<n:
            if up:
                sol.append(mat[i][j])
                i-=1
                j+=1

                if j>=n:
                    j-=1
                    i+=2
                    up=False
                elif i<0:
                    i+=1
                    up=False
            else:
                sol.append(mat[i][j])
                i+=1
                j-=1

                if i>=m:
                    i-=1
                    j+=2
                    up=True
                elif j<0:
                    j+=1
                    up=True

        return sol