class Solution {
public:
    bool selfDivide(int num){
        if(num<9) return true;
        string n=to_string(num);
        for(char c:n){
            int digit=c-'0';
            if(digit==0 || num%digit!=0) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;++i){
            if(selfDivide(i)) ans.push_back(i);
        }
        return ans;
    }
};