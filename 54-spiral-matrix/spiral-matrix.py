class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # define borders and move them around and move to right left top or bottom
        l=0
        r=len(matrix[0])-1
        t=0
        b= len(matrix)-1

        sol = []

        while t<=b and l<=r:
            for i in range(l,r+1):
                sol.append(matrix[t][i])
            t+=1
            
            for i in range(t,b+1):
                sol.append(matrix[i][r])
            r-=1
            
            if t<=b: 
                for i in range(r,l-1,-1):
                    sol.append(matrix[b][i])
                b-=1

            if l<=r:
                for i in range(b,t-1,-1):
                    sol.append(matrix[i][l])
                l+=1
        
        return sol