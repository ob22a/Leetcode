class Solution {
public:
    bool isPossible(const vector<int>& arr, const int& limit, const int& amount){
        int count=1;
        long long sum=0;
        for(int num:arr){
            if(sum+num>limit){
                ++count;
                sum=num;
            }
            else sum+=num;
        }
        return count<=amount;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        while(l<r){
            int mid=l+(r-l)/2;
            if(!isPossible(nums,mid,k)) l=mid+1;
            else r=mid;
        }
        return l;
    }
};