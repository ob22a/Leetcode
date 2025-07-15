class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        // Find first occurence of positive no
        int l=0,r=n-1;
        int posIdx=n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if((mid==0 || nums[mid-1]<=0) && nums[mid]>0){
                posIdx=mid; break;
            }
            else if(nums[mid]<=0) l=mid+1;
            else r=mid-1;
        }
        // Last occurence of negative no
        l=0,r=n-1;
        int negIdx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((mid==n-1 || nums[mid+1]>=0) && nums[mid]<0){
                negIdx=mid; break;
            }
            else if(nums[mid]>=0) r=mid-1;
            else l=mid+1;
        }
        int neg=negIdx+1,pos=n-posIdx;
        return max(neg,pos);
    }
};