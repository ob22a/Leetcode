class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        string word;

        for(const char& c:s){
            if(c==' '){
                words.push_back(word);
                word.clear();
            }
            else word+=c;
        }
        words.push_back(word);

        vector<string> ordered(words.size());
        for(const string& str:words){
            int idx=str.back()-'0'-1;
            ordered[idx]=str.substr(0,str.size()-1);
        }

        string sol;
        for(const string& str:ordered){
            sol+=str;
            sol+=" ";
        }
        sol.pop_back();
        return sol;
    }
};