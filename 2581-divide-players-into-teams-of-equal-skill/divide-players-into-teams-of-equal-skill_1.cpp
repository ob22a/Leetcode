class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2) return 1ll*skill[0]*skill[1];
        int total=0;
        for(int num:skill) total+=num;

        sort(skill.begin(),skill.end());
        
        int l=0,r=n-1,no=n/2;
        long long sol=0;
        if(total%no!=0) return -1;
        while(l<r){
            if(skill[l]+skill[r]==total/no) sol+=(1ll*skill[l]*skill[r]);
            else return -1;
            ++l; --r;
        }
        return sol;
    }
};
