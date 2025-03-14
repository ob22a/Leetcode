class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy=0
        sell=1
        profit=0
        if len(prices)==1:
            return profit
        while buy<len(prices)-1 and sell<len(prices):
            if prices[buy]>prices[sell]:
                buy=sell
                if sell<len(prices)-1:
                    sell+=1
            if prices[buy]<=prices[sell]:
                if profit<(prices[sell]-prices[buy]):
                    profit=prices[sell]-prices[buy]
                sell+=1
        return profit
