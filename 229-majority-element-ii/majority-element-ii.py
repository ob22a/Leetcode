class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Same as majority element I but we need to track two winners 
        win1,vote1 = 0,0
        win2,vote2 = 0,0

        for num in nums:
            if(num==win1): vote1+=1
            elif(num==win2): vote2+=1
            elif(vote1==0):
                win1=num
                vote1+=1
            elif(vote2==0):
                win2=num
                vote2+=1
            else:
                vote1-=1
                vote2-=1
        
        # check if the vote is correct 
        vote1,vote2=0,0

        count1 = nums.count(win1)
        count2 = nums.count(win2)

        sol = list([])

        if count1>len(nums)/3: sol.append(win1)
        if (count2>len(nums)/3 and win1!=win2): sol.append(win2)

        return sol