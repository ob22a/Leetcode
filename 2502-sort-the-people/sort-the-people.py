class Solution:
    def sortPeople(self, names, heights):
        #using merge sort 
        def merge(a,b):
            c=[]
            n1=len(a)
            n2=len(b)

            i=0
            j=0
            while i<n1 and j<n2:
                if a[i]<b[j]:
                    c.append(a[i])
                    i+=1
                else:
                    c.append(b[j])
                    j+=1
            
            if i<n1: 
                for idx in range(i,n1):
                    c.append(a[idx])
            elif j<n2:
                for idx in range(j,n2):
                    c.append(b[idx])

            return c
        
        def mergeSort(a):
            n = len(a)
            if n<=1:
                return a
            return merge(mergeSort(a[:n//2]),mergeSort(a[n//2:]))
            
        n = len(heights)
        array = [(heights[i],names[i]) for i in range(n)]
        array = mergeSort(array)

        return [name for _,name in array[::-1]]        