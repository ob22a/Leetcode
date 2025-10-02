class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> last(26, 0);  
        long long dp = 1;         
        
        for (char c : s) {
            long long temp = (2 * dp) % MOD;
            
            if (last[c-'a']>0) temp = (temp - last[c-'a'] + MOD) % MOD;
            last[c -'a'] = dp;
            dp = temp;
        }

        return (dp-1+MOD) % MOD;
    }
};