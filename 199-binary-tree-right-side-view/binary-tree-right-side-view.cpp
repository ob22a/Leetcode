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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        stack<pair<TreeNode*,int>> stk;
        if(root) stk.push({root,0});

        while(!stk.empty()){
            auto [node,lvl]=stk.top(); stk.pop();
            if(sol.size()==lvl){
                sol.push_back(node->val);
            }
            if(node->left) stk.push({node->left,lvl+1});
            if(node->right) stk.push({node->right,lvl+1});
        }
        
        return sol;
    }
};