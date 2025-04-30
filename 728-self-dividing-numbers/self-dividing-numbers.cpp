class Solution {
public:
    bool selfDivide(int num){
        int n=num;
        while(n>0){
            int digit=n%10;
            n/=10;
            if(digit==0 || num%digit!=0 ) return false;
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