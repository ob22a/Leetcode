class Solution {
public:
    void heapify(vector<int>& arr,int cur,int size){
        int left=cur*2+1,right=cur*2+2,largest=cur;

        if(left<size && arr[left]>arr[cur]) largest=left;
        if(right<size && arr[right]>arr[largest]) largest=right;

        if(cur!=largest){
            swap(arr[cur],arr[largest]);
            heapify(arr,largest,size);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;--i){
            heapify(nums,i,n);
        }
        int heapSize=n;
        for(int i=1;i<k;++i){
            swap(nums[0],nums[heapSize-1]);
            --heapSize;
            heapify(nums,0,heapSize);
        }
        return nums[0];
    }
};