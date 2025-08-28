class Solution {
public:
    int gcf(int a,int b){
        while(b){
            int temp=a;
            a=b;
            b=temp%b;
        }
        return a;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        int sol=0;

        auto bkt = [&](auto&& self,vector<bool> seen,vector<int> gcfs){
            if(gcfs.size()*2==n){
                sort(gcfs.begin(),gcfs.end());
                int sum=0;
                for(int i=1,j=0;j<n/2;++j,++i){
                    sum+=(i*gcfs[j]);
                }
                sol=max(sol,sum);
                return;
            }

            int first=-1;
            for(int i=0;i<n;++i){
                if(!seen[i]){
                    first=i;
                    break;
                }
            }
            seen[first]=true;

            for(int i=first;i<n;++i){
                if(!seen[i]){
                    seen[i]=true;
                    gcfs.push_back(gcf(nums[first],nums[i]));
                    self(self,seen,gcfs);
                    gcfs.pop_back();
                    seen[i]=false;
                }
            }
            seen[first]=false;
        };

        bkt(bkt,vector<bool>(n,false),{});
        return sol;
    }
};