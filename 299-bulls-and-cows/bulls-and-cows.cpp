class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int nums[10];
        for(char c:secret) nums[c-'0']++;

        int b=0;
        int c=0;
        for(int i=0;i<n;++i){
            int idx=guess[i]-'0';
            if(nums[idx]!=0){
                ++c;
                nums[idx]--;
            }
            if(guess[i]==secret[i]){
                ++b; --c;
            }
        }
        string sol=to_string(b)+"A"+to_string(c)+"B";
        return sol;
    }
};