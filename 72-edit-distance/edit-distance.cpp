class Solution {
public:
    int f(string word1, string word2, int idx1, int idx2){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;

        if(word1[idx1]==word2[idx2]) return f(word1,word2,idx1-1,idx2-1);
        
        return 1 + min({
            f(word1,word2,idx1-1,idx2), // Delete character
            f(word1,word2,idx1,idx2-1), // Add character
            f(word1,word2,idx1-1,idx2-1) // Replace character
        });
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() + 1, n2 = word2.size() + 1;
        vector<int> dp(n2,0);
        vector<int> temp(n2,0);
        for(int i=0;i<n2;++i) temp[i] = i;

        for(int idx1=1;idx1<n1;idx1++){
            dp[0] = idx1;
            for(int idx2=1;idx2<n2;++idx2){
                dp[idx2] = (word1[idx1-1]==word2[idx2-1]) ?
                                temp[idx2-1] :
                                1 + min({ temp[idx2], dp[idx2-1], temp[idx2-1]});
            }
            temp = dp;
        }

        return temp[n2-1];
    }
};