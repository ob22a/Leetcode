class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = strs[0]
        for word in strs:
            j =0
            while j<len(prefix) and j<len(word) and prefix[j]==word[j]: j+=1
            prefix = prefix[:j]
            if not prefix: return ""

        return prefix