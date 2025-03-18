class Solution {
public:
    int romanToInt(string s) {
        vector<int> values(91); //Since ASCII value of Z is 90
        values['I']=1;
        values['V']=5;
        values['X']=10;
        values['L']=50;
        values['C']=100;
        values['D']=500;
        values['M']=1000;
        int result=0;

        for(int i=0;i<s.size()-1;++i){
            if(values[s[i]]<values[s[i+1]]) result-=values[s[i]];
            else result+=values[s[i]];
        }
        return result+values[s.back()];
    }
};