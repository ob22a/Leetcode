class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        n = len(s)
        vowels = {'a','e','i','o','u'}
        start = 0
        sol = 0
        while start<k:
            if s[start] in vowels:
                sol+=1
            start+=1

        left = 0
        cur_vowels = sol
        for right in range(start,n):
            if s[left] in vowels:
                cur_vowels-=1
            
            if s[right] in vowels:
                cur_vowels+=1

            sol = max(sol,cur_vowels)
            left+=1
        
        return sol