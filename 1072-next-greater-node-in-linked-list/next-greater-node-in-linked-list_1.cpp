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
        if(!head) return {};

        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }

        vector<int> sol(nums.size());
        stack<int> s;

        for(int i=nums.size()-1;i>=0;--i){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty()) sol[i]=0;
            else sol[i]=s.top();

            s.push(nums[i]);
        }
        return sol;
    }
};
