class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();
        vector<int> sol(size,-1);
        stack<int> s;
        
        for(int i=2*size-1;i>=0;--i){
            int idx=i%size;
            while(!s.empty() && s.top()<=nums[idx]){
                s.pop();
            }
            if(i<size){
                if(!s.empty()) sol[idx]= s.top();
            }
            s.push(nums[idx]);
        }
        return sol;
    }
};