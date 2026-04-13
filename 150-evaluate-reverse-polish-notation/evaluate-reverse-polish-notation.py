class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        numStk = []
        
        for c in tokens:
            #print(numStk)
            if c.lstrip('-').isdigit():
                numStk.append(int(c))
            else:
                num1 = numStk.pop()
                num2 = numStk.pop()

                if c=="+":
                    numStk.append(num2+num1)
                elif c=="-":
                    numStk.append(num2-num1)
                elif c=="*":
                    numStk.append(num2*num1)
                else:
                    numStk.append(int(num2/num1))
        
        return numStk[0]