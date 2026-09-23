class Solution:
    def sumOfLargestPrimes(self, s: str) -> int:
        n=len(s)
        prime_or_not = dict()
        primes = []

        def check_prime(num):
            if num<2:
                return False

            if num==2:
                return True

            for n in range(2,int(num**0.5)+1):
                if num%n==0:
                    return False
            
            return True

        for i in range(n):
            for j in range(i,n):
                num = int(s[i:j+1])
                if num in prime_or_not:
                    continue
                
                res = check_prime(num)
                prime_or_not[num]=res
                if res:
                    primes.append(num)

        primes.sort()
        res = 0
        for x in primes[-3:]:
            res+=x

        return res
        
