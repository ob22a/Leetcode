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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*,long long,long long>> s;
        s.push({root,LLONG_MIN,LLONG_MAX});

        while(!s.empty()){
            auto [node,minVal,maxVal] = s.top();
            s.pop();

            if(node->val<=minVal || node->val>=maxVal) return false;
            if(node->left) s.push({node->left,minVal,node->val});
            if(node->right) s.push({node->right,node->val,maxVal});   
        }

        return true;
    }
};