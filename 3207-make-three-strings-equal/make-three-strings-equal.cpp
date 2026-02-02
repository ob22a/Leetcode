class Solution {
public:
    int lcp(vector<string>& vec){
        int len = 0;
        string sol = vec[0];
        
        for(string str:vec){
            int i=0;
            while(i<str.size() && i<sol.size() && sol[i]==str[i]) ++i;
            sol = sol.substr(0,i);
        }
        cout<<sol;
        return sol.size();
    }
    int findMinimumOperations(string s1, string s2, string s3) {
        // sol = len - longest common prefix
        vector<string> vec = {s1,s2,s3};
        int lcp_len = lcp(vec);
        if(lcp_len==0) return -1;

        int n = s1.size()+s2.size()+s3.size();
        return n-lcp_len*3;

    }
};