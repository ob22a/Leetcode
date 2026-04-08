class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n1 = len(nums1)
        n2 = len(nums2)
        
        nextGreater=[-1]*n2
        stk = []

        for i in range(n2-1,-1,-1):
            while stk and stk[-1]<nums2[i]:
                stk.pop()
            if stk:
                nextGreater[i]=stk[-1]
            stk.append(nums2[i])
        
        #print(nextGreater)

        sol=[-1]*n1
        for i in range(n1):
            idx = nums2.index(nums1[i])
            sol[i]=nextGreater[idx]
        
        return sol