class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        # insertion sort
        n = len(heights)
        for i in range(n-1):
            j=i+1
            h=heights[j]
            name = names[j]

            while j>0 and heights[j-1]<h:
                heights[j]=heights[j-1]
                names[j]=names[j-1]
                j-=1
            
            heights[j]=h
            names[j]=name
        
        # print(names)
        #print(heights)
        return names