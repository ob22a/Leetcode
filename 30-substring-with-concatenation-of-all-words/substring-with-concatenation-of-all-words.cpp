class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].size();
        unordered_map<string,int> wordFreq;
        for(string word:words) wordFreq[word]++;
        vector<int> sol;

        for(int i=0;i<len;++i){
            int left=i,right=i;
            unordered_map<string,int> windowFreq;
            int count=0;

            while(right+len<=s.size()){
                string word=s.substr(right,len);
                right+=len;
                if(wordFreq.find(word)!=wordFreq.end()){
                    windowFreq[word]++;
                    count++;

                    while(left<right && windowFreq[word]>wordFreq[word]){
                        string leftWord = s.substr(left,len);
                        windowFreq[leftWord]--;
                        left+=len;
                        --count;
                    }

                    if(count==words.size()) sol.push_back(left);
                } else {
                    windowFreq.clear();
                    left=right;
                    count=0;
                }
            }
        }
        return sol;
    }
};