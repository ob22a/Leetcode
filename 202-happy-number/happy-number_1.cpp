class Solution {
public:
    int sum_of_square(int n){
        int result=0;
        while(n>0){
            result+=(n%10)*(n%10);
            n/=10;
        }
        return result;
    }
    
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(true){
            if(n==1) return true;
            if(seen.count(n)) return false;
            seen.insert(n);
            n=sum_of_square(n);
        }
    }
};
