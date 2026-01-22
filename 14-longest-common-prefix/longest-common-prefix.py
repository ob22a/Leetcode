class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        
        prefix = ""
        for chars in zip(*strs): # Array got unpacked and zip matches based on index
            if len(set(chars)) == 1:
                prefix += chars[0]
            else:
                break
                
        return prefix
