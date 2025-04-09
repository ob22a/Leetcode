class Solution {
public:
    bool canWinNim(int n) {
        /*1,2,3,5,6,7,9,10,... This are some of the possible cases where you would win.
        The common thing here is that they are not multiples of 4 n%4!=0;
        */
        return n%4!=0;
    }
};