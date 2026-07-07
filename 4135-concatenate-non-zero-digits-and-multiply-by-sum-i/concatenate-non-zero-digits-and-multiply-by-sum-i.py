class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x=0
        total=0

        temp = n
        rev=0

        while temp:
            last_digit=temp%10
            if last_digit!=0:
                total+=last_digit
                
                rev*=10
                rev+=last_digit
                
            temp//=10
        
        sol=0
        
        while rev:
            sol*=10
            sol+=rev%10
            rev//=10
            
        
        return sol*total
        

