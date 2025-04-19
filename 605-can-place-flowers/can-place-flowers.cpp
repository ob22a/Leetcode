class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size(),count=0;
        for(int i=0;i<len;++i){
            if(flowerbed[i]==0){
                if((i-1<0 || flowerbed[i-1]==0) && (i+1==len || flowerbed[i+1]==0 )){
                        flowerbed[i]=1;
                        ++count;
                        ++i;
                }
            }
        }
        return count>=n;
    }
};