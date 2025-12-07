class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> sol;
        int patternSize = pattern.size();

        for(string query:queries){
            int i=0,j=0;
            int n = query.size();
            bool flag = true;

            while(i<n){
                if(query[i]>='A' && query[i]<='Z'){
                    if(j < patternSize && query[i] == pattern[j]) ++j;
                    else{
                        flag = false;
                        break;
                    }
                }
                else if(j<patternSize && query[i]==pattern[j]) ++j; 
                ++i;
            }

            if(j!=patternSize) flag=false;
            sol.push_back(flag);
        }

        return sol;
    }
};