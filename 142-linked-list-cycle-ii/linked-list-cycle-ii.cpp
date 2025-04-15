/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* intersectionNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return slow;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* current=head;

        ListNode* intersection=intersectionNode(head);
        if(!intersection) return nullptr;

        while(intersection!=current){
            current=current->next;
            intersection=intersection->next;
        }
        return current;
    }
};