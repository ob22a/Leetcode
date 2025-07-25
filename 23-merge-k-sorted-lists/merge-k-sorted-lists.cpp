/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    typedef pair<int,ListNode*> T;

    struct Compare {
    bool operator()(const T& a, const T& b) {
        return a.first > b.first;  // Min-heap: smaller 'int' has higher priority
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<T,vector<T>,Compare> minHeap;
        for(ListNode* head:lists){
            if(head!=nullptr) minHeap.push({head->val,head});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur=dummy;
        
        while(!minHeap.empty()){
            ListNode* node=minHeap.top().second;
            minHeap.pop();
            cur->next=node;
            if(node->next!=nullptr){
                minHeap.push({node->next->val,node->next});
            }
            cur=cur->next;
        }
        return dummy->next;
    }
};