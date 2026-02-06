class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        counter = [0 for i in range(26)]
        for char in words[0]:
            idx = ord(char)-ord("a")
            counter[idx]+=1
        
        for i in range(1,len(words)):
            second_counter = [0 for i in range(26)]
            for char in words[i]:
                idx = ord(char)-ord("a")
                second_counter[idx]+=1
            
            for j in range(26):
                counter[j] = min(counter[j],second_counter[j])
        
        sol =[]
        for idx,num in enumerate(counter):
            for _ in range(num):
                sol.append(chr(idx+ord("a")))
        
        return sol