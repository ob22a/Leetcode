class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        if(freq.size()<=k) return 0;

        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(const auto& [c,n]:freq) minHeap.push(n);

        int sol=0,toDelete=freq.size()-k;
        while(toDelete--){
            sol+=minHeap.top();
            minHeap.pop();
        }
        
        return sol;
    }
};