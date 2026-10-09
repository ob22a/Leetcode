class Solution:
    def minInsertions(self, s: str) -> int:
        need = 0
        sol = 0

        for ch in s:
            if ch=='(':
                if need % 2 == 1:
                    sol+=1
                    need-=1
                    
                need += 2
            else:
                need -= 1

                if need < 0:
                    sol += 1
                    need = 1

        return sol + need
