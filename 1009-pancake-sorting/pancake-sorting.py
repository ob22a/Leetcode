class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        # Get the largest place it on top then reverse the whole thing and put it in the bottom 
        # For each portion find idx (of the largest) add idx+1 and n to the sequence and move the right pointer
        n = len(arr)
        sequence = []

        def reverse(start,end):
            while start<=end:
                arr[start],arr[end]=arr[end],arr[start]
                start+=1
                end-=1

        for i in range(n-1,0,-1):
            largest_idx = 0
            for j in range(1,i+1):
                if arr[j]>arr[largest_idx]:
                    largest_idx=j
            if largest_idx!= i: 
                if largest_idx!=0: 
                    reverse(0,largest_idx)
                    sequence.append(largest_idx+1)
                sequence.append(i+1)
                reverse(0,i)

        return sequence