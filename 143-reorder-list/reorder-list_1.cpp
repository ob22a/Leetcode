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
        if(!head->next) return;

        vector<ListNode*> nodes;
        while(head){
            nodes.push_back(head);
            head=head->next;
        }
        int i=0,j=nodes.size()-1;
        while(i<j){
            nodes[i]->next=nodes[j];
            nodes[j]->next=nodes[i+1];
            ++i;
            --j;
        }
        nodes[i]->next=nullptr;
        head=nodes[0];
    }
};
