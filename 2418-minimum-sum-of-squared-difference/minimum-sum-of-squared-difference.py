class Solution:
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        diff = [abs(x - y) for x, y in zip(nums1, nums2)]

        k = k1 + k2
        n = len(diff)

        if sum(diff)<k:
            return 0

        diff.sort(reverse=True)
        diff.append(0)

        for i in range(1,n+1):
            cost = (diff[i-1]-diff[i])*i
            if cost>k:
                q,r = divmod(k,i)
                hi = diff[i-1]-q
                return hi**2*(i-r) + (hi-1)*(hi-1)*r + sum(x*x for x in diff[i:n])
            k-=cost
        
        return 0