class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # We can use the voting method 
        # if it is majority then its cummulative vote is the largest 

        winner = nums[0]
        vote = 1

        for num in nums:
            if winner==num:
                vote+=1
            else: 
                vote-=1
                if vote<=0:
                    winner=num
                    vote = 1
        
        return winner