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
    ListNode* doubleIt(ListNode* head) {
        stack<int> doubled;

        while(head){
            int val=2*head->val;
            if(val>9){
                if(!doubled.empty()) doubled.top()+=1;
                else doubled.push(1);
            }
            doubled.push(val%10);
            head=head->next;
        }

        ListNode* cur=nullptr;
        while(!doubled.empty()){
            ListNode* node = new ListNode(doubled.top());
            node->next=cur;
            cur=node;
            doubled.pop();
        }
        return cur;
    }
};
