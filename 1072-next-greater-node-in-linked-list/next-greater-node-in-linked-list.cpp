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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> monotonicStack;
        vector<int> sol;
        int index=0;

        for(ListNode* cur=head;cur!=nullptr;cur=cur->next, ++index){
            sol.push_back(0);
            while(!monotonicStack.empty() && monotonicStack.top().first<cur->val){
                sol[monotonicStack.top().second]=cur->val;
                monotonicStack.pop();
            }
            monotonicStack.push({cur->val,index});
        }
        return sol;
    }
};