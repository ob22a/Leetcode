class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n=len(s)
        
        def binary(char):
            match char:
                case "A":
                    return 0b00
                case "C":
                    return 0b01
                case "G":
                    return 0b10
            
            return 0b11

        mask=0
        seen=defaultdict(int)
        sol=[]

        for i in range(n):
            mask=((mask<<2)|binary(s[i]))&0xFFFFF
            if i>=9:
                if seen[mask]==1:
                    sol.append(s[i-9:i+1])
                
                seen[mask]+=1
        
        return sol