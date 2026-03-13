class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)

        # Greedy doesn't work 
        # Sliding window to subtract what we won't take

        cur_sum = sum(cardPoints[:n-k])
        score = total-cur_sum
        left = 0
        for right in range(n-k,n):
            cur_sum+=cardPoints[right]-cardPoints[left]
            score=max(score,total-cur_sum)
            left+=1
        
        return score