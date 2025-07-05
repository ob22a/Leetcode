class Solution {
public:
    int findLucky(vector<int>& arr) {
        int counter[501]={};
        for(int num:arr) counter[num]++;
        for(int i=500;i>=1;--i){
            if(counter[i]==i) return i;
        }
        return -1;
    }
};