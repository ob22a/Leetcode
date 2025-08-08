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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        ListNode* ptr=dummy;
        ListNode* end=head;
        ListNode* start=head;
        
        while(end!=nullptr){
            int i=1;
            while(i!=k && end!=nullptr){
                end=end->next;
                i++;
            }
            if(end!=nullptr){
                ListNode* nextNode=end->next;
                ListNode* prev=nullptr;
                end->next=nullptr;
                while(start!=nullptr){
                    ListNode* next=start->next;
                    start->next=prev;
                    prev=start;
                    start=next;
                }
                ptr->next=prev;
                start=nextNode;
                end=nextNode;
            }
            else ptr->next=start;
            
            while(ptr->next) ptr=ptr->next;
        }
        return dummy->next;
    }
};