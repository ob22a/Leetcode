class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;

        for (int n : nums) {
            int crt = round(cbrt(n));
            if (crt * crt * crt == n && isPrime(crt)) {
                total += 1 + crt + crt * crt + n;
                continue;
            }

            for (int d = 2; d * d <= n; ++d) {
                if (n % d == 0) {
                    int other = n / d;
                    if (d != other && isPrime(d) && isPrime(other)) {
                        total += 1 + d + other + n;
                    }
                    break;
                }
            }
        }

        return total;
    }
};
