class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        alphanum = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','0','1','2','3','4','5','6','7','8','9'}

        if len(s.strip())<=1:
            return True
        l=0
        r=len(s)-1
        while l<r:
            if s[l] in alphanum and s[r] in alphanum:
                if s[l].lower()!=s[r].lower():
                    return False
                l+=1
                r-=1
            if s[l] not in alphanum:
                l+=1
            if s[r] not in alphanum:
                r-=1
        return True