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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sol = new ListNode();
        ListNode* current=sol;

        int carry=0;
        while(l1 || l2){
            int sum = carry;
            carry=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            if(sum<=9) current->next=new ListNode(sum);
            else{
                current->next=new ListNode(sum%10);
                carry+=sum/10;
            }
            current=current->next;
        }

        if(carry==1) current->next=new ListNode(carry);
        return sol->next;
    }
};
