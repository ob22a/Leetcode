/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        
        for(int x:nums){
            TreeNode* cur = new TreeNode(x);
            TreeNode* lastRemoved = nullptr;

            while(!stk.empty() && stk.top()->val<x){
                lastRemoved=stk.top();
                stk.pop();
            }
            cur->left = lastRemoved;
            if(!stk.empty()) stk.top()->right=cur;
            stk.push(cur);
        }

        while(stk.size()>1) stk.pop();
        return stk.top();
    }
};