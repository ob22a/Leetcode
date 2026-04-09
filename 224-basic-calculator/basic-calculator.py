class Solution:
    def calculate(self, s: str) -> int:
        stk=[]
        res=0
        cur=0
        sign=1

        for c in s:
            if c.isdigit():
                cur=cur*10+int(c)
            elif c=="+":
                res+=sign*cur
                sign=1
                cur=0
            elif c=="-":
                res+=sign*cur
                sign=-1
                cur=0
            elif c=="(":
                stk.append(res)
                stk.append(sign)
                res=0
                sign=1
            elif c==")":
                res+=sign*cur
                cur=0
                res*=stk.pop()
                res+=stk.pop()
        
        res+=sign*cur
        return res