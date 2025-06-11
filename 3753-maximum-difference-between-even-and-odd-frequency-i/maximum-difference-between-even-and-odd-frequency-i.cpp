class Solution {
public:
    int maxDifference(string s) {
        int letters[26]={};
        for(char c:s) letters[c-'a']++;
        int largest=0,smallest=INT_MAX;
        for(int count:letters){
            if(count!=0 && count%2==0) smallest=min(smallest,count);
            else largest=max(largest,count);
        }
        return largest-smallest;
    }
};