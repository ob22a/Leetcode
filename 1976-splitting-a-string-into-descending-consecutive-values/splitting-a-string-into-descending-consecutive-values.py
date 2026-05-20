class Solution:
    def splitString(self, s: str) -> bool:
        splits = []

        def f(i,s):          
            n=len(s)
            #print(splits)

            if i>=n:
                #print("End",splits)
                if len(splits)<2:
                    return False
                
                for index in range(len(splits)-1):
                    if splits[index]-splits[index+1]!=1:
                        return False
                
                return True

            for idx in range(i+1,n+1):
                splits.append(int(s[i:idx]))
                if f(idx,s):
                    return True
                splits.pop()
            
            return False
        
        return f(0,s)