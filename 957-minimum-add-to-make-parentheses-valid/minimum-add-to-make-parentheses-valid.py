class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        faulty = 0
        stk = []

        for c in s:
            if c=="(":
                stk.append(c)
            else:
                if stk:
                    stk.pop()
                else:
                    faulty+=1

        return len(stk) + faulty