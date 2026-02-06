class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row = [0 for _ in range(26)]
        sol = []

        for i in range(26):
            char = chr(i+ord("a"))
            if char in "qwertyuiop":
                row[i]=1
            elif char in "asdfghjkl":
                row[i]=2
            else: row[i]=3

        for word in words:
            chr_idx = ord(word[0].lower())-ord("a")
            row_pos = row[chr_idx]
            isPossible = True

            for char in word:
                char_row_pos = row[(ord(char.lower())-ord("a"))]
                if char_row_pos!=row_pos:
                    isPossible = False
                    break
            if isPossible:
                sol.append(word)
        
        return sol