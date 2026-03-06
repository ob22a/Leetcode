class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # To avoid the risk of overwriting go from the end to start

        i=m-1
        j=n-1
        length = m+n

        for k in range(length-1,-1,-1):
            if i>=0 and (j<0 or nums1[i]>nums2[j]):
                nums1[k]=nums1[i]
                i-=1
            else:
                nums1[k]=nums2[j]
                j-=1