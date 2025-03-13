class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res=[[1]]
        for i in range(2,rowIndex+2):
            val=[1]*i
            for j in range(1,i-1):
                val[j]=res[-1][j-1]+res[-1][j]
            res.append(val)

        return res[-1]
