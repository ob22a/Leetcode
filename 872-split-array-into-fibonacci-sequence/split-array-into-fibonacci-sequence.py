class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        LIMIT = 1 << 31
        n = len(num)

        def fib_seq(idx, seq):
            if idx == n:
                return len(seq) >= 3

            nxt = seq[-1] + seq[-2]
            if nxt >= LIMIT:
                return False

            nxt_str = str(nxt)

            if not num.startswith(nxt_str, idx):
                return False

            seq.append(nxt)
            if fib_seq(idx + len(nxt_str), seq):
                return True
            seq.pop()

            return False

        for i in range(1, n):
            if num[0] == '0' and i > 1:
                break

            num1 = int(num[:i])
            if num1 >= LIMIT:
                break

            for j in range(i + 1, n):
                if num[i] == '0' and j - i > 1:
                    break

                num2 = int(num[i:j])
                if num2 >= LIMIT:
                    break

                seq = [num1, num2]

                if fib_seq(j, seq):
                    return seq

        return []