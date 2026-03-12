class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        n=len(word)
    
        def isVowelSubstring():
            for c in countVowels:
                if c==0: return False
            
            return True
        def getIdx(char):
            if char=="a": return 0
            if char=="e": return 1
            if char=="i": return 2
            if char=="o": return 3
            return 4
        def isVowel(char):
            return char in ["a","e","i","o","u"]


        count = 0

        for i in range(n):
            if not isVowel(word[i]): continue 
            countVowels = [0]*5 # A E I O U
            for j in range(i,n):
                if not isVowel(word[j]): break
                countVowels[getIdx(word[j])]+=1
                if isVowelSubstring():
                    count+=1
        
        return count