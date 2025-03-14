class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen={}
        for num in nums:
            if num in seen:
                seen[num]+=1
            else:
                seen[num]=1
        
        for key,value in seen.items():
            if value==1:
                return key