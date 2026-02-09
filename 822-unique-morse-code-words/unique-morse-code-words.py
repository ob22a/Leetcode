class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse_alpha = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        seen = set() # stores the transformation seen so far
        for word in words:
            morse = ""
            for char in word:
                idx = ord(char)-ord("a")
                morse+=morse_alpha[idx]
            seen.add(morse)

        return len(seen)
