class Solution {
public:
    string longestNiceSubstring(string s) {
        string sol="";
        for(int i=0;i<s.size();++i){
            array<bool,26> capital={};
            array<bool,26> small={};

            for(int j=i;j<s.size();++j){
                bool isCapital=false;
                if(s[j]<'a') isCapital=true;
                if(isCapital) capital[s[j]-'A']=true;
                else small[s[j]-'a']=true;

                if(capital==small){
                    if(sol.size()<j-i+1){
                        sol=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return sol;
    }
};