class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t binary=0;
        for(int i=0;i<32;++i){
            binary=(binary<<1) | (n&1);//since 1 is 00001 or 000001 n&1 gives the last digit
            n>>=1;
        }
        return binary;
    }
};
