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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;

        ListNode* last=head,*first=head;

        for(int i=0;i<n;++i){
            first=first->next;
        }
        while(first && first->next){
            last=last->next;
            first=first->next;
        }
        if(!first) head=head->next;
        else last->next=last->next->next;

        return head;
    }
};