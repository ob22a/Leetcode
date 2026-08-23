class Solution:
    def sumGame(self, num: str) -> bool:
        n=len(num)
        # count ? and sum for left and right
        left_sum,right_sum=0,0
        count_left,count_right=0,0
        
        for i in range(n//2):
            if num[i]!='?':
                left_sum+=int(num[i])
            else:
                count_left+=1
        
        for i in range(n//2,n):
            if num[i]!='?':
                right_sum+=int(num[i])
            else:
                count_right+=1
        
        return (count_left+count_right)%2==1 or left_sum-right_sum!=9*(count_right-count_left)//2