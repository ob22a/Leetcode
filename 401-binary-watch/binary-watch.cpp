class Solution {
public:
    int countBits(int num){
        int count=0;
        while(num>0){
            if(num&1) ++count;
            num>>=1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn>=9) return {}; 
        vector<string> sol;

        for(int hour=0;hour<12;++hour){
            for(int minute=0;minute<60;++minute){
                int numOfBits=countBits(hour)+countBits(minute);
                if(numOfBits==turnedOn){
                    string time=to_string(hour)+":";
                    if(minute<10) time+="0";
                    time+=to_string(minute);
                    sol.push_back(time);
                }
            }
        }
        return sol;
    }
};