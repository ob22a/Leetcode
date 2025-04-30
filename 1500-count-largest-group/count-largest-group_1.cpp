class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> size;
        
        for(int i=1;i<=n;++i){
            int sum =0;
            int num=i;
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            size[sum]++;
        }

        int largest=0,count=0;
        for(const auto& pair:size){
            if(pair.second>largest){
                count=1;
                largest=pair.second;
            }
            else if(pair.second==largest) ++count;
        }
        return count;
    }
};
