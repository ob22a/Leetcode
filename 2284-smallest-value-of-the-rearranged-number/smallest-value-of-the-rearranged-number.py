class Solution:
    def smallestNumber(self, num: int) -> int:
        isNegative = num<0
        if isNegative:
            num*=-1
        arr = []
        x = num
        while x:
            arr.append(x%10)
            x//=10

        arr.sort()
        n = len(arr)

        zero_stop = 0 
        while zero_stop<n and arr[zero_stop]==0:
            zero_stop+=1
        
        if zero_stop == n:
            return 0
            
        sol = 0
        if isNegative:
            for i in range(n-1,zero_stop-1,-1):
                sol+=arr[i]
                sol*=10
        else:
            sol+=arr[zero_stop]
            sol*=pow(10,zero_stop)

            for i in range(zero_stop+1,n):
                sol*=10
                sol+=arr[i]
                
        
        if isNegative:
            sol*=pow(10,zero_stop-1)
            sol*=-1
        
        return int(sol)