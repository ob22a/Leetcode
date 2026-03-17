class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        changes = [0]*(n+1)

        for l,r,direction in shifts:
            val = 1 if direction==1 else -1
            changes[l]+=val
            changes[r+1]-=val
        
        for i in range(1,n):
            changes[i]+=changes[i-1]
        

        sol = list(s)
        
        for i in range(n):
            shift = changes[i] % 26
            sol[i]=chr((ord(s[i])+shift-ord('a'))%26 + ord('a'))
        
        return "".join(sol)