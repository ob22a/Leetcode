class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        bool row1[26]={},row2[26]={},row3[26]={};

        for(char c:string("qwertyuiop")) row1[c-'a']=true;
        for(char c:string("asdfghjkl")) row2[c-'a']=true;
        for(char c:string("zxcvbnm")) row3[c-'a']=true;

        vector<string> sol;
        for(string word:words){
            bool* row;
            char first=tolower(word[0]);
            if(row1[first-'a']) row=row1;
            else if(row2[first-'a']) row=row2;
            else row=row3;

            int i=1;
            while(i<word.size()){
                if(!row[tolower(word[i])-'a']) break;
                ++i;
            }
            if(i==word.size()) sol.push_back(word);
        }
        return sol;
    }
};