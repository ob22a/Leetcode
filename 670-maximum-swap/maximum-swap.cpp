class Solution {
public:
    int maximumSwap(int num) {
        vector<int> last(10,-1);
        string s=to_string(num);
        for(int i=0;i<s.size();++i) last[s[i]-'0']=i;

        for(int i=0;i<s.size();++i){
            for(int j=9;j>s[i]-'0';--j){
                if(last[j]>i){
                    swap(s[i],s[last[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};