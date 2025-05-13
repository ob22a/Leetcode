class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        int zeroCount=0;
        for(int num:arr){
            if(num!=0) seen.insert(num);
            else{
                ++zeroCount;
                if(zeroCount>1) return true;
            }
        }
        for(int num:arr){
            if(seen.count(num*2)) return true;
        }
        return false;
    }
};