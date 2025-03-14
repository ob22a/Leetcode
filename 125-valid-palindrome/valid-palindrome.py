class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s.strip())<=1:
            return True
        l=0
        r=len(s)-1
        while l<r:
            if s[l].isalnum() and s[r].isalnum():
                if s[l].lower()!=s[r].lower():
                    return False
                l+=1
                r-=1
            if not s[l].isalnum():
                l+=1
            if not s[r].isalnum():
                r-=1
        return True