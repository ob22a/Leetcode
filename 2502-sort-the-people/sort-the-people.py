class Solution:
    def sortPeople(self, names, heights):
        # Quick sort 
        def quickSort(arr,left,right):
            if left>=right:
                return

            pivot = right-1 # Assume pivot is always at the end
            i = left
            for j in range(left,right):
                if arr[j]>arr[pivot]:
                    arr[i],arr[j]=arr[j],arr[i]
                    i+=1
            arr[i],arr[pivot]=arr[pivot],arr[i]
            
            quickSort(arr,left,i)
            quickSort(arr,i+1,right)
        
        n = len(heights)
        array = [(heights[i],names[i]) for i in range(n)]

        quickSort(array,0,n)
        #print(array)

        return [name for _,name in array]