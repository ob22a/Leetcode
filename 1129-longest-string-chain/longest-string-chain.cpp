class Solution {
public:
    bool valid(string longer, string shorter){
        if(longer.size()!=shorter.size()+1) return false;
        int i=0,j=0;
        while(i<longer.size()){
            if(longer[i]==shorter[j]){
                ++i; ++j;
            } else ++i;
        }

        return j==shorter.size();
    }

    static bool comp(string word1,string word2){
        return word1.size()<word2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);

        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (valid(words[i], words[j])) dp[i]=max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};