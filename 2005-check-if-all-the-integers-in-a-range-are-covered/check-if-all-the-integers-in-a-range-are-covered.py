class Solution(object):
    def isCovered(self, ranges, left, right):
        """
        :type ranges: List[List[int]]
        :type left: int
        :type right: int
        :rtype: bool
        """
        # We can start from left it should be in idx =0 range meaning val>=[1] and [0]<=val if that breaks return false
        # if the upper limit is 5 we don't have to go from 2-5 we should jump

        for l,r in sorted(ranges, key=lambda x: x[0]):
            if left>right: return True
            if l <= left <= r:
                # left is covered, jump to r+1
                left = r + 1
            elif r < left:
                # range ends before left, skip
                continue
            else:
                # left is less than l → gap detected, not covered
                return False
        
        return left>right