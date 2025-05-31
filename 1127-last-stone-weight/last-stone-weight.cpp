class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int weight:stones) maxHeap.push(weight);
        while(maxHeap.size()>1){
            int max1=maxHeap.top(); maxHeap.pop();
            int max2=maxHeap.top(); maxHeap.pop();
            if(max1!=max2) maxHeap.push(abs(max1-max2));
        }
        return (maxHeap.empty())?0:maxHeap.top();
    }
};