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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        deque<ListNode*> nodes;
        ListNode* temp = head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        
        k=k%nodes.size();
        if(k==0) return head;

        for(int i=0;i<k;++i){
            ListNode* node = nodes.back(); nodes.pop_back();
            nodes.back()->next=nullptr;
            node->next=nodes.front();
            nodes.push_front(node);
        }
        return nodes[0];
    }
};
