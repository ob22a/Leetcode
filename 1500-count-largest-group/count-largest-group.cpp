class Solution {
public:
    int countLargestGroup(int n) {
        //Since the maximum bucket is 9+9+9+9=36 we can make arr of size 37 to avoid hashing 

        int groupSize[37];

        for(int i=1;i<=n;++i){
            int sum=0,num=i;
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            groupSize[sum]++;
        }

        int count=0,largest=0;

        for(int c:groupSize){
            if(c>largest){
                count=1;
                largest=c;
            }
            else if(c==largest) ++count;
        }

        return count;
    }
};