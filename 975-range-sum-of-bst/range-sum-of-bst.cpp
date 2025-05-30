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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> stk;
        stk.push(root);

        int result=0;
        while(!stk.empty()){
            TreeNode* node = stk.top(); stk.pop();
            if(node->val>=low && node->val<=high) result+=node->val;

            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        return result;
    }
};