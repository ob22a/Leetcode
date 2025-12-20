class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        vector<int> idxs;

        for(int i=0;i<n;++i){
            if(words[i]==target) idxs.push_back(i);
        }
        if(idxs.size()==0) return -1;

        int sol = INT_MAX;
        for(int idx:idxs) sol = min({
            sol,
            abs(idx-startIndex),
            n-abs(idx-startIndex)
        });
        return sol;
    }
};