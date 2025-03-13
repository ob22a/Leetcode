class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res=[[1]]
        for i in range(2,numRows+1):
            val=[1]
            for j in range(1,i-1):
                val.append(res[-1][j-1]+res[-1][j])
            val.append(1)
            res.append(val)

        return res