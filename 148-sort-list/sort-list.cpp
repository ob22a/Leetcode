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
    ListNode* mergeSort(ListNode* &left,ListNode* &right){
        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        while(left && right){
            if(left->val<right->val){
                cur->next=left;
                left=left->next;
            }
            else{
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }
        if(right) cur->next=right;
        if(left) cur->next=left;

        return dummy->next;
    }
    ListNode* middle(ListNode* head){
        ListNode *slow=head,*fast=head;
        ListNode* prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=middle(head);
        ListNode* mid=(prev)?prev->next:nullptr;
        prev->next=nullptr;
        
        if(mid!=head){
            ListNode* left=sortList(head);
            ListNode* right=sortList(mid);
            return mergeSort(left,right);
        }

        return nullptr;
    }
};