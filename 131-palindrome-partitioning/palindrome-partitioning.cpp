class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            ++start; --end;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> pali;
        int n=s.size();

        auto bkt = [&](auto&& self, int idx){
            if(idx==n){
                sol.push_back(pali);
                return;
            }

            for(int i=idx;i<n;++i){
                if(isPalindrome(s,idx,i)){
                    pali.push_back(s.substr(idx,i-idx+1));
                    self(self,i+1);
                    pali.pop_back();
                }
            }
        };

        bkt(bkt,0);
        return sol;
    }
};