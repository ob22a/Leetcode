class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        num1,count1 = fruits[0],0
        num2,count2 = -1,0
        types = 1

        left = 0
        sol = 0 
        for right in range(n):
            if num2==-1 and fruits[right]!=num1:
                num2=fruits[right]
                types+=1
                
            if fruits[right]==num1:
                count1+=1
            elif fruits[right]==num2:
                count2+=1
            else:
                while types>1:
                    if fruits[left]==num1:
                        count1-=1
                    elif fruits[left]==num2:
                        count2-=1
                    
                    if count1<=0 or count2<=0:
                        types-=1
                    
                    if count1<=0:
                        num1=num2
                        count1=count2
                
                    left+=1
                num2=fruits[right]
                count2=1
                types+=1

            # print(num1,num2)
            # print(count1,count2)
            # print("Left: ",left)
            # print("Right: ",right)
            sol=max(sol,right-left+1)
        
        return sol