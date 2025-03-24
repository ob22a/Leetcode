class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(auto it=digits.end()-1;it>=digits.begin();--it){
           if(*it!=9){
                (*it)++;
                return digits;
           }
           else (*it)=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};