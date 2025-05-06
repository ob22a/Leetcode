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
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        //Finding the middle
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reverse the second half
        ListNode* prev=nullptr, *cur=slow->next;
        while(cur){
            ListNode* nextTemp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextTemp;
        }
        slow->next=nullptr; //break the link

        //Merge
        ListNode* first=head;
        while(prev){
            ListNode* node1=first->next, *node2=prev->next;
            first->next=prev;
            prev->next=node1;
            first=node1;
            prev=node2;
        } 
    }
};