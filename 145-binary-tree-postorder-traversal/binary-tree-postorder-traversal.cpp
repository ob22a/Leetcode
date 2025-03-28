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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> sol;
        vector<TreeNode*>stack={root};
        unordered_set<TreeNode*> seen;
        
        while(!stack.empty()){
            TreeNode* current=stack.back();
            if(current->left && !seen.count(current->left)) stack.push_back(current->left);
            else if(current->right && !seen.count(current->right)) stack.push_back(current->right);
            else{
                seen.insert(current);
                sol.push_back(current->val);
                stack.pop_back();
            }
        }
        return sol;
    }
};