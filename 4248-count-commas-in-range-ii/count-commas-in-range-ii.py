class Solution:
    def countCommas(self, n: int) -> int:
        count = 0
        
        upper = 9999
        lower = 1000

        while n>=lower:
            upper = min(upper,n)
            num_comma = (len(str(upper))-1)//3

            count+=num_comma*(upper-lower+1)
            lower*=10
            upper=upper*10+9
        
        return count