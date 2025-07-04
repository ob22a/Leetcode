class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> sol(s.size(),s.size());
        int i=0;
        for(int j=0;j<s.size();++j){
            if(s[j]==c){
                while(i<=j){
                    sol[i]=j-i;
                    ++i;
                }
            }
        }

        // Backward Logic
        i=s.size()-1;
        for(int j=s.size()-1;j>=0;--j){
            if(s[j]==c){
                while(j<=i){
                    sol[i]=min(sol[i],i-j);
                    --i;
                }
            }
        }
        return sol;
    }
};