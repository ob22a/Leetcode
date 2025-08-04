class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int type=0;
        int maxNum=0;
        vector<int> freq(n,0);

        for(int i=0,j=0;j<n;++j){
            if(freq[fruits[j]]==0) ++type;
            freq[fruits[j]]++;
            while(type>2){
                if((--freq[fruits[i++]])==0) --type;
            }
            maxNum=max(maxNum,j-i+1);
        }
        return maxNum;
    }
};