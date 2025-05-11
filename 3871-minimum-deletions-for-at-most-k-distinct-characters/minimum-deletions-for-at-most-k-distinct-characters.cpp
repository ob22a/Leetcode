class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        if(freq.size()<=k) return 0;

        vector<int>count;
        for(const auto& [c,n]:freq){
            count.push_back(n);
        }

        sort(count.begin(),count.end());

        int sol=0;
        for(int i=0;i<freq.size()-k;++i){
            sol+=count[i];
        }
        
        return sol;
    }
};