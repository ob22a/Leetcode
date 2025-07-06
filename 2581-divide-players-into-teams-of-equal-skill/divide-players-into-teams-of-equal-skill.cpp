class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2) return 1ll*skill[0]*skill[1];

        int freq[2001]={};
        int total=0;
        for(int num:skill){
            total+=num;
            freq[num]++;
        }

        int no=n/2;
        if(total%no!=0) return -1;
        int pairSum=total/no;

        long long sol=0;
        for(int num:skill){
            if(freq[num]!=0){
                int comp = pairSum-num;
                if(freq[comp]==0) return -1;
                if(comp==num && freq[comp]<2) return -1;
                freq[num]--; freq[comp]--;
                sol+=(1ll*num*comp);
            }
        }
        return sol;
    }
};