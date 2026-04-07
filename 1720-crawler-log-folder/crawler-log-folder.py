class Solution:
    def minOperations(self, logs: List[str]) -> int:
        sol = 0
        for log in logs:
            if log == "../":
                if sol>0:
                    sol-=1
            elif log!="./":
                sol+=1
        return sol