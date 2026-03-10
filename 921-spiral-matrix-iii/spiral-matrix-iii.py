class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        amount_move = 1
        sol=[[rStart,cStart]]

        while len(sol)<rows*cols:
            for _ in range(1,amount_move+1):
                cStart+=1
                if rStart<rows and cStart<cols and rStart>=0 and cStart>=0:
                    sol.append([rStart,cStart])

            for _ in range(1,amount_move+1):
                rStart+=1
                if rStart<rows and cStart<cols and rStart>=0 and cStart>=0:
                    sol.append([rStart,cStart])

            for _ in range(1,amount_move+2):
                cStart-=1
                if rStart<rows and cStart<cols and rStart>=0 and cStart>=0:
                    sol.append([rStart,cStart])

            for _ in range(1,amount_move+2):
                rStart-=1
                if rStart<rows and cStart<cols and rStart>=0 and cStart>=0:
                    sol.append([rStart,cStart])

            amount_move+=2
        
        return sol
