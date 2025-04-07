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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *slow=head, *fast=head, *prev=nullptr;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;
        if(prev) prev->next=nullptr;

        ListNode* current = slow;
        ListNode* middle=nullptr;

        while(current){
            ListNode* next=current->next;
            current->next=middle;
            middle=current;
            current=next;
        }
        
        while(middle){
            if(head->val!=middle->val) return false;
            head=head->next;
            middle=middle->next;
        }

        return true;
    }
};