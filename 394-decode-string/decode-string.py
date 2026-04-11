class Solution:
    def decodeString(self, s: str) -> str:
        n = len(s)
        
        numStack = []
        valStack = []
        cur = 0

        for c in s:
            if c.isdigit():
                cur=cur*10+int(c)
            elif c=="]":
                stk = []
                while valStack[-1]!="[":
                    stk.append(valStack.pop())
                valStack.pop()

                txt = "".join(stk[::-1])
                repeats = numStack.pop()

                for _ in range(repeats):
                    valStack.append(txt)
                
            else:
                if cur!=0:
                    numStack.append(cur)
                valStack.append(c)
                cur=0
        
        return "".join(valStack)