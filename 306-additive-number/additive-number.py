class Solution():
    def isAdditiveNumber(self, num):
        def rec(a, b, s):
            if not s:
                return True
            c = str(a + b)
            return s.startswith(c) and rec(b, int(c), s[len(c):])

        for i in range(1, len(num)):
            for j in range(i + 1, len(num)):

                if (num[0] == '0' and i > 1) or (num[i] == '0' and j > i + 1):
                    continue

                if rec(int(num[:i]), int(num[i:j]), num[j:]):
                    return True

        return False