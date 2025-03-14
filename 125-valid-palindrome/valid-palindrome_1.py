class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        alphanum = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','0','1','2','3','4','5','6','7','8','9'}

        if len(s.strip())<=1:
            return True
        modified_s=""
        for char in s:
            if char in alphanum:
                modified_s+=char.lower()  
        j=-1
        for i in range(len(modified_s)//2):
            if modified_s[i]!=modified_s[j]:
                return False
            j-=1
        
        return True
