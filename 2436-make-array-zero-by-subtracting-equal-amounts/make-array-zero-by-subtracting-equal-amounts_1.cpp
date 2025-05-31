class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       priority_queue<int,vector<int>, greater<int>> minHeap;
       int maximum=0;
       
       for(int num:nums){
            minHeap.push(num);
            maximum=max(maximum,num);
       } 
       while(!minHeap.empty() && minHeap.top()==0) minHeap.pop();
       
       int count=0,prevDec=0;
       
       while(!minHeap.empty() && maximum!=0){
            int val=(minHeap.top()-prevDec>=0)?minHeap.top()-prevDec:0;
            maximum-=val; 
            prevDec+=val;
            minHeap.pop();
            if(val!=0) ++count;
       }

       return count;
    }
};
