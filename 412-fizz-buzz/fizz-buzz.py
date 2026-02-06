class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        sol = []
        for num in range(1,n+1):
            if num%15==0: sol.append("FizzBuzz")
            elif num%5==0: sol.append("Buzz")
            elif num%3==0: sol.append("Fizz")
            else: sol.append(str(num))

        return sol