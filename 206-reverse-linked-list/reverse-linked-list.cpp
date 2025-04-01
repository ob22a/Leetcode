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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* current=head;

        while(current){
            ListNode* next = current->next; //This is very critical because when current->next gets modified this modification also occurs at the head
            current->next=prev;
            prev=current;
            current=next;
        }

        return prev;
    }
};