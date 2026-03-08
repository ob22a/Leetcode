class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i=0
        j=0
        n1=len(firstList)
        n2=len(secondList)

        sol=[]
        while i<n1 and j<n2:
            start1=firstList[i][0]
            end1=firstList[i][1]
            start2 = secondList[j][0]
            end2 = secondList[j][1]

            intersection = (max(start1,start2),min(end1,end2))
            if intersection[0]<=intersection[1]:
                sol.append(intersection)
            
            if end1<end2: i+=1
            else: j+=1
        
        return sol