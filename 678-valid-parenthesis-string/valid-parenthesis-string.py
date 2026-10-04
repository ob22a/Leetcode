class Solution:
    def checkValidString(self, s: str) -> bool:
        n=len(s)

        op=0
        cl=0

        for c in s:
            if c=="(":
                op+=1
                cl+=1
            elif c==")":
                op-=1
                cl-=1
            else:
                op-=1
                cl+=1
            
            op = max(0,op)
            if cl<0:
                return False
        
        return op==0
