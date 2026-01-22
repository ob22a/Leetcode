class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        s= dict()
        sol = list([])

        for (idx,num) in enumerate(nums):
            if (target-num) in s:
                sol.append(s[target-num]);
                sol.append(idx)
                break
            s[num]=idx

        return sol